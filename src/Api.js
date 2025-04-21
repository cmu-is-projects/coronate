// api.js
export async function fetchPlayers() {
  const response = await fetch("/players");
  const json = await response.json();
  return json.players;
}

export async function fetchTournaments() {
  const response = await fetch("/tournaments");
  const json = await response.json();
  return json.tournaments;
}

export async function createPlayer(player) {
  const response = await fetch("/players", {
    method: "POST",
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify(player)
  });

  const data = await response.json();
  return data;
}
