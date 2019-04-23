let component = ReasonReact.statelessComponent("RepeatButton");

let make = (~isActive=false, ~onClick, _children) => {
  ...component,
  render: _self => {
    let className =
      switch (isActive) {
        | false => Styles.repeatButtonActive
        | true => Styles.repeatButton
        };
    <Button className onClick>...{ReasonReact.string("Loop")}</Button>
  }
};
