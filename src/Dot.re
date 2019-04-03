let component = ReasonReact.statelessComponent("Dot");

let make = (~onClick, ~isActive=false, ~isPlaying=false, ~content, _children) => {
  ...component,
  render: _self => {
    let className =
      switch (isActive, isPlaying) {
      | (false, false) => Styles.dot
      | (true, false) => Styles.dotActive
      | (false, true) => Styles.dotPlaying
      | (true, true) => Styles.dotPlayingAndActive
      };
    <button
      onClick=(_ => onClick())
      className
    >
      {ReasonReact.string(content)}
    </button>
  }
};
