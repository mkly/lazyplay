let component = ReasonReact.statelessComponent("Intro");

let make = _children => {
  ...component,
  render: _self => {
    <div>
      <h1>{ReasonReact.string("Lazyplay")}</h1>
      <p>{ReasonReact.string("Lazyplay attempts to play along with the song you made using a simple ")}<a href="https://en.wikipedia.org/wiki/Markov_chain" target="_blank">{ReasonReact.string("markov chain")}</a></p>
      <p>{ReasonReact.string("If you make each section similar, it tends to do a bit better. Also, adding come chords(multiple notes at the same time), also helps.")}</p>
      <p>{ReasonReact.string("First, create a song by clicking some notes. Then, click \"Train\" and Lazyplay will attempt to play along with what you wrote. Don't like it? Press \"Train\" again and Lazyplay will take another shot.")}</p>
      <p>{ReasonReact.string("\"Loop\" will stay on one section and \"Show Generated\" will show you what Lazyplay wrote. Clicking on the squares at the bottom will allow you to move between the different sections.")}</p>
    </div>
  }
}
