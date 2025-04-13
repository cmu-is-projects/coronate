/*
  Copyright (c) 2022 John Jackson.

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
open Belt

module Splash = {
  @react.component
  let make = () => {


  let (apiMessage, setApiMessage) = React.useState(() => "Click the button to fetch players")

  let handleFetch = () =>
  Api.fetchPlayers()
  ->Js.Promise.then_(playersJson => {
    let message = Js.Json.stringifyWithSpace(playersJson, 2)
    setApiMessage(_ => message)
    Js.Promise.resolve()
  }, _)
  ->ignore

  let (firstName, setFirstName) = React.useState(() => "")
  let (lastName, setLastName) = React.useState(() => "")
  let (rating, setRating) = React.useState(() => 1200)

  let handleSubmit = (event: ReactEvent.Form.t) => {
  ReactEvent.Synthetic.preventDefault(event)

  // Generate a simple unique id for now
  let uniqueSuffix = NanoId.generate()
  let id = firstName ++ lastName ++ "_" ++ uniqueSuffix

  let player = Js.Dict.empty()
  Js.Dict.set(player, "id", Js.Json.string(id))
  Js.Dict.set(player, "firstName", Js.Json.string(firstName))
  Js.Dict.set(player, "lastName", Js.Json.string(lastName))
  Js.Dict.set(player, "rating", Js.Json.number(float_of_int(rating)))
  Js.Dict.set(player, "matchCount", Js.Json.number(0.0))
  Js.Dict.set(player, "type_", Js.Json.string("person"))

  let jsonPlayer = Js.Json.object_(player)

  Api.createPlayer(jsonPlayer)
  ->Js.Promise.then_(response => {
    setApiMessage(_ => Js.Json.stringifyWithSpace(response, 2))
    Js.Promise.resolve()
  }, _)
  ->ignore
}



    <div className="pages__container">
      <aside className="pages__hint">
        <ol>
          <li className="pages__hint-item">
            <button className="button-primary" onClick={_ => Db.loadDemoDB()}>
              {React.string("Click here to load the demo data")}
            </button>
            {React.string(" (optional)")}
          </li>
          <li className="pages__hint-item">
            <Icons.ArrowLeft />
            {React.string(" Select a menu item.")}
          </li>
          <li className="pages__hint-item"> {React.string("Start creating your tournaments!")} </li>

          <li className="pages__hint-item">
            <button className="button-primary" onClick={_ => handleFetch()}>
              {React.string("Fetch Players from API")}
            </button>
            <p> {React.string(apiMessage)} </p>
          </li>

          <form onSubmit={handleSubmit}>
            <label>
              {"First Name: "->React.string}
              <input
                type_="text"
                value={firstName}
                onChange={event => {
                  let value = ReactEvent.Form.target(event)["value"]
                  setFirstName(_ => value)
                }}
              />
            </label>
            <br />
            <label>
              {"Last Name: "->React.string}
              <input
                type_="text"
                value={lastName}
                onChange={event => {
                  let value = ReactEvent.Form.target(event)["value"]
                  setLastName(_ => value)
                }}
              />
            </label>

            <br />
            <label>
              {"Rating: "->React.string}
              <input
                type_="number"
                value={Int.toString(rating)}
                onChange={event => {
                  let target = ReactEvent.Form.target(event)
                  let valueStr = target["value"]
                  switch Int.fromString(valueStr) {
                  | Some(value) => setRating(_ => value)
                  | None => ()
                  }
                }}
              />
            </label>


            <br />
            <button className="button-primary" type_="submit">
              {React.string("Add Player")}
            </button>
          </form>



        </ol>
        <Utils.Notification kind=Warning>
          <div>
            <p>
              {React.string("Coronate does not require an account.")}
              <br />
              {React.string("It saves your data locally in your browser.")}
            </p>
            <p>
              {React.string("To manage your data, visit the ")}
              <Router.Link to_=Options> {"Options"->React.string} </Router.Link>
              {React.string(" page.")}
            </p>
          </div>
        </Utils.Notification>
      </aside>
      <div className="pages__title">
        <div className="pages__title-icon">
          <img src=Utils.WebpackAssets.logo alt="" height="96" width="96" />
        </div>
        <div className="pages__title-text">
          <h1 className="title" style={ReactDOM.Style.make(~fontSize="40px", ())}>
            {React.string("Coronate")}
          </h1>
          <p className={"pages__subtitle caption-30"}> {React.string("Tournament manager")} </p>
        </div>
      </div>
      <footer className={"pages__footer body-20"}>
        <div className="pages__footer-left">
           <img src=Utils.WebpackAssets.qGlogo alt="" height="96" width="192" />
        </div>
        <div className="pages__footer-right">
          <p> {React.string(`Copyright ${HtmlEntities.copy} John Jackson.`)} </p>
          <p>
            <a className="pages__footer-link" href=Utils.issues_url>
              {React.string("Suggestions and bug reports are welcome.")}
            </a>
          </p>
          <p> {React.string("Coronate is free software.")} </p>
          <p>
            <a className="pages__footer-link" href=Utils.github_url>
              {React.string("Source code is available")}
            </a>
            {React.string(" under the ")}
            <a className="pages__footer-link" href=Utils.license_url>
              {React.string("Mozilla Public License 2.0")}
            </a>
            {React.string(".")}
          </p>
        </div>
      </footer>
    </div>
  }
}

let log2 = num => log(num) /. log(2.0)

let fixNumber = num =>
  if num < 0.0 || num == infinity || num == neg_infinity {
    0.0
  } else {
    num
  }

module TimeCalculator = {
  let updateFloat = (dispatch, minimum, event) => {
    ReactEvent.Form.preventDefault(event)
    let value =
      ReactEvent.Form.currentTarget(event)["value"]
      ->Float.fromString
      ->Option.getWithDefault(minimum)
    let safeValue = value < minimum ? minimum : value
    dispatch(_ => safeValue)
  }

  let updateInt = (dispatch, minimum, event) => {
    ReactEvent.Form.preventDefault(event)
    let value =
      ReactEvent.Form.currentTarget(event)["value"]->Int.fromString->Option.getWithDefault(minimum)
    let safeValue = value < minimum ? minimum : value
    dispatch(_ => safeValue)
  }

  let title = "Time calculator"

  @react.component
  let make = () => {
    let minPlayers = 0
    let minBreakTime = 0
    let minTotalTime = 0.5
    let (players, setPlayers) = React.useState(() => 2)
    let (breakTime, setBreakTime) = React.useState(() => 5)
    let (totalTime, setTotalTime) = React.useState(() => 4.0)
    <div className="content-area">
      <h1> {title->React.string} </h1>
      <p className="caption-30">
        {"Estimate the time requirements for planning your Swiss-system tournament."->React.string}
      </p>
      <form>
        <table style={ReactDOM.Style.make(~margin="0", ())}>
          <tbody>
            <tr>
              <td>
                <label htmlFor="playerCount"> {React.string("Player count ")} </label>
              </td>
              <td>
                <input
                  id="playerCount"
                  type_="number"
                  value={Int.toString(players)}
                  onChange={updateInt(setPlayers, minPlayers)}
                  min={Int.toString(minPlayers)}
                  style={ReactDOM.Style.make(~width="40px", ())}
                />
              </td>
            </tr>
            <tr>
              <td>
                <label htmlFor="breakTime"> {React.string("Breaks between rounds ")} </label>
              </td>
              <td>
                <input
                  id="breakTime"
                  type_="number"
                  value={Int.toString(breakTime)}
                  onChange={updateInt(setBreakTime, minBreakTime)}
                  step=5.0
                  min={Int.toString(minBreakTime)}
                  style={ReactDOM.Style.make(~width="40px", ())}
                />
                {React.string(" minutes")}
              </td>
            </tr>
            <tr>
              <td>
                <label htmlFor="totalTime"> {React.string("Total time available ")} </label>
              </td>
              <td>
                <input
                  id="totalTime"
                  type_="number"
                  value={Float.toString(totalTime)}
                  onChange={updateFloat(setTotalTime, minTotalTime)}
                  step=0.5
                  min={Float.toString(minTotalTime)}
                  style={ReactDOM.Style.make(~width="40px", ())}
                />
                {React.string(" hours")}
              </td>
            </tr>
          </tbody>
        </table>
      </form>
      <dl>
        <dt className="title-20"> {React.string("Round count")} </dt>
        <dd> {players->Int.toFloat->log2->ceil->fixNumber->React.float} </dd>
        <dt className="title-20"> {React.string("Maximum time control")} </dt>
        <dd>
          <span className="title-20">
            {((totalTime *. 60.0 /. players->Int.toFloat->log2->ceil -.
              Int.toFloat(breakTime)) /. 2.0)
            ->ceil
            ->fixNumber
            ->React.float}
            {React.string(" minutes")}
          </span>
          <span className="caption-20">
            {React.string(" = ((")}
            <strong className="monospace"> {totalTime->React.float} </strong>
            {React.string(" × 60 ÷ ⌈log₂(")}
            <strong className="monospace"> {players->React.int} </strong>
            {React.string(")⌉) - ")}
            <strong className="monospace"> {breakTime->React.int} </strong>
            {React.string(") ÷ 2")}
          </span>
        </dd>
      </dl>
    </div>
  }
}

module NotFound = {
  @react.component
  let make = () => <p className="content-area"> {React.string("Page not found.")} </p>
}
