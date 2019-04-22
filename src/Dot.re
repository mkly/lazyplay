let component = ReasonReact.statelessComponent("Dot");

let make = (~onClick, ~isActive=false, ~isPlaying=false, ~isGenerated=false, ~content, _children) => {
  ...component,
  render: _self => {
    let className =
      switch (isActive, isPlaying, isGenerated) {
      | (false, false, false) => Styles.dot
      | (false, false, true) => Styles.dotGenerated
      | (true, false, _) => Styles.dotActive
      | (false, true, _) => Styles.dotPlaying
      | (true, true, _) => Styles.dotPlayingAndActive
      };
    <button
      onClick=(_ => onClick())
      className
    >
      {ReasonReact.string(content)}
    </button>
  }
};
