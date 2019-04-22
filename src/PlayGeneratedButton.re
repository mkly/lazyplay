let component = ReasonReact.statelessComponent("PlayGeneratedButton");

let make = (~isActive=false, ~onClick, _children) => {
  ...component,
  render: _self => {
    let className =
      switch (isActive) {
        | true => Styles.playGeneratedButtonActive
        | false => Styles.playGeneratedButton
        };
    <button className onClick>{ReasonReact.string("Play Generated")}</button>
  }
};
