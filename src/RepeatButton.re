let component = ReasonReact.statelessComponent("RepeatButton");

let make = (~isActive=false, ~onClick, _children) => {
  ...component,
  render: _self => {
    let className =
      switch (isActive) {
        | true => Styles.repeatButtonActive
        | false => Styles.repeatButton
        };
    <div className onClick>{ReasonReact.string("Repeat")}</div>
  }
};
