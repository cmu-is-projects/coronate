// src/Api.res

// Api.res
@module("./Api") external fetchPlayers: unit => Js.Promise.t<Js.Json.t> = "fetchPlayers"
@module("./Api") external fetchTournaments: unit => Js.Promise.t<Js.Json.t> = "fetchTournaments"
@module("./Api") external createPlayer: Js.Json.t => Js.Promise.t<Js.Json.t> = "createPlayer"
