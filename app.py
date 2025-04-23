from flask import Flask, jsonify, request, redirect
from flask_pymongo import PyMongo
import json
import requests
from flask_cors import CORS
import os
from dotenv import load_dotenv
load_dotenv(dotenv_path=".env.flask")


app = Flask(__name__)
app.config["MONGO_URI"] = "mongodb://localhost:27017/coronate_db"
mongo = PyMongo(app)

CORS(app)

@app.route('/')
def index():
    return jsonify(message="Welcome to the Coronate API!")

@app.route('/players', methods=['GET', 'POST'])
def handle_players():
    if request.method == 'POST':
        data = request.get_json()
        if 'id' not in data:
            return jsonify(message="Player ID is required"), 400
        mongo.db.players.insert_one(data)
        return jsonify(message="Player added successfully"), 201
    else:
        players = mongo.db.players.find()
        players_dict = {player['id']: player for player in players}
        for player_id in players_dict:
            players_dict[player_id].pop('_id', None)
        return jsonify(players=players_dict), 200

@app.route('/players/<player_id>', methods=['PUT', 'DELETE'])
def modify_player(player_id):
    if request.method == 'PUT':
        update_data = request.get_json()
        result = mongo.db.players.update_one({'id': player_id}, {'$set': update_data})
        if result.modified_count:
            return jsonify(message="Player updated successfully"), 200
        else:
            return jsonify(message="No player found or data unchanged"), 404
    elif request.method == 'DELETE':
        result = mongo.db.players.delete_one({'id': player_id})
        if result.deleted_count:
            return jsonify(message="Player deleted successfully"), 200
        else:
            return jsonify(message="No player found"), 404

def format_tournament(tournament):
    tournament.pop('_id', None)  # Remove the MongoDB '_id'
    if 'roundList' not in tournament:
        tournament['roundList'] = []  
    
    formatted_rounds = []
    for round_group in tournament.get('roundList', []): 
        formatted_group = [
            {
                'id': match['id'],
                'whiteId': match['whiteId'],
                'blackId': match['blackId'],
                'whiteNewRating': match['whiteNewRating'],
                'blackNewRating': match['blackNewRating'],
                'whiteOrigRating': match['whiteOrigRating'],
                'blackOrigRating': match['blackOrigRating'],
                'result': match['result']
            } for match in round_group
        ]
        formatted_rounds.append(formatted_group)
    tournament['roundList'] = formatted_rounds
    return tournament


@app.route('/tournaments', methods=['GET', 'POST'])
def handle_tournaments():
    if request.method == 'POST':
        data = request.get_json()
        if 'id' not in data:
            return jsonify(message="Tournament ID is required"), 400
        data['byeQueue'] = []  # Hardcoding an empty byeQueue for now
        data['tieBreaks'] = ["median", "solkoff", "cumulative", "cumulativeOfOpposition"]
        data['scoreAdjustments'] = []
        mongo.db.tournaments.insert_one(data)
        return jsonify(message="Tournament added successfully"), 201
    else:
        tournaments = mongo.db.tournaments.find()
        tournaments_dict = {tournament['id']: format_tournament(tournament) for tournament in tournaments}
        return jsonify(tournaments=tournaments_dict), 200

@app.route('/tournaments/<tournament_id>', methods=['PUT', 'DELETE'])
def modify_tournament(tournament_id):
    if request.method == 'PUT':
        update_data = request.get_json()
        result = mongo.db.tournaments.update_one({'id': tournament_id}, {'$set': update_data})
        if result.modified_count:
            return jsonify(message="Tournament updated successfully"), 200
        else:
            return jsonify(message="No tournament found or data unchanged"), 404
    elif request.method == 'DELETE':
        result = mongo.db.tournaments.delete_one({'id': tournament_id})
        if result.deleted_count:
            return jsonify(message="Tournament deleted successfully"), 200
        else:
            return jsonify(message="No tournament found"), 404

@app.route('/players/all', methods=['DELETE'])
def delete_all_players():
    result = mongo.db.players.delete_many({})
    return jsonify(message=f"Deleted {result.deleted_count} players"), 200

@app.route('/tournaments/all', methods=['DELETE'])
def delete_all_tournaments():
    result = mongo.db.tournaments.delete_many({})
    return jsonify(message=f"Deleted {result.deleted_count} tournaments"), 200

@app.route('/config', methods=['GET', 'POST'])
def handle_config():
    if request.method == 'POST':
        data = request.get_json()
        mongo.db.config.replace_one({}, data, upsert=True)  # GPT'd, replace the existing config or insert if none exists
        return jsonify(message="Configuration updated successfully"), 201
    else:
        config = mongo.db.config.find_one()
        if config:
            config.pop('_id', None)  
        return jsonify(config=config if config else {}), 200

@app.route('/complete_data', methods=['GET'])
def get_complete_data():
    # Fetch config
    config = mongo.db.config.find_one() or {}
    config.pop('_id', None)

    # Fetch players
    players_cursor = mongo.db.players.find()
    players = {player['id']: player for player in players_cursor}
    for player_id in players:
        players[player_id].pop('_id', None)

    # Fetch tournaments
    tournaments_cursor = mongo.db.tournaments.find()
    tournaments = {tournament['id']: format_tournament(tournament) for tournament in tournaments_cursor}

    # Combine all 
    complete_data = {
        "config": config,
        "players": players,
        "tournaments": tournaments
    }
    return jsonify(complete_data)


GITHUB_CLIENT_ID = os.environ.get("GITHUB_CLIENT_ID")
GITHUB_CLIENT_SECRET = os.environ.get("GITHUB_CLIENT_SECRET")
FRONTEND_URL = os.getenv("FRONTEND_URL", "https://rook-cmuis.net")
@app.route("/callback")
def github_oauth_callback():
    code = request.args.get("code")
    print(f"Received code: {code}")

    res = requests.post(
        "https://github.com/login/oauth/access_token",
        data={
            "client_id": GITHUB_CLIENT_ID,
            "client_secret": GITHUB_CLIENT_SECRET,
            "code": code,
        },
        headers={"Accept": "application/json"}
    )

    data = res.json()
    print(data)
    access_token = data.get("access_token")

    # Redirect back to frontend with token in query string
    return redirect(f"{FRONTEND_URL}/options?token={access_token}")
    # return redirect(f"http://localhost:3000/options?token={access_token}")


if __name__ == '__main__':
    app.run(host="0.0.0.0", port=5000, debug=os.getenv("FLASK_ENV") != "production")
