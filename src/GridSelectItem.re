let component = ReasonReact.statelessComponent("GridSelectItem");

let make = (~isActive=false, ~onClick, _children) => {
  ...component,
  render: _self => {
    let className =
      switch (isActive) {
        | true => Styles.gridSelectItemActive
        | false => Styles.gridSelectItem
        };
    <div className onClick />
  }
};
