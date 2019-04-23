let component = ReasonReact.statelessComponent("TrainButton");

let make = (~onClick, _children) => {
  ...component,
  render: _self => {
    <Button onClick className=Styles.trainButton>...{ReasonReact.string("Train")}</Button>
  }
};
