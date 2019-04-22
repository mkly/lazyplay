let component = ReasonReact.statelessComponent("Intro");

let make = _children => {
  ...component,
  render: _self => {
    <div>
      <h1>{ReasonReact.string("Lazyplay")}</h1>
      <p>{ReasonReact.string("Lazyplay attempts(poorly) to write a new song from the song you made using a simple ")}<a href="https://en.wikipedia.org/wiki/Markov_chain" target="_blank">{ReasonReact.string("markov chain")}</a></p>
      <p>{ReasonReact.string("If you make each section similar, it tends to do a bit better")}</p>
    </div>
  }
}
