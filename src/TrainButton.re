let component = ReasonReact.statelessComponent("TrainButton");

let make = (~onClick, _children) => {
  ...component,
  render: _self => {
    <div onClick className=Styles.trainButton>{ReasonReact.string("Train")}</div>
  }
};
