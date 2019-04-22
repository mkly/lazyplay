let component = ReasonReact.statelessComponent("TrainButton");

let make = (~onClick, _children) => {
  ...component,
  render: _self => {
    <button onClick className=Styles.trainButton>{ReasonReact.string("Train")}</button>
  }
};
