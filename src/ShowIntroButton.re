let component = ReasonReact.statelessComponent("ShowIntroButton");

let make = (~isIntroVisible=true, ~onClick, _children) => {
  ...component,
  render: _self => {
    let buttonText =
      switch (isIntroVisible) {
        | true => "Hide Instructions"
        | false => "Show Instructions"
        };
    <Button className=Styles.introButton onClick>...{ReasonReact.string(buttonText)}</Button>
  }
};
