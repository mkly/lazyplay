let component = ReasonReact.statelessComponent("GridSelect");

let make = (~activeMatrixId, ~onGridSelectItemClick, _children) => {
  ...component,
  render: _self => {
    <div className=Styles.gridSelect>
      <GridSelectItem
        onClick=(_ => onGridSelectItemClick(0))
        isActive=(activeMatrixId == 0)
      />
      <GridSelectItem
        onClick=(_ => onGridSelectItemClick(1))
        isActive=(activeMatrixId == 1)
      />
      <GridSelectItem
        onClick=(_ => onGridSelectItemClick(2))
        isActive=(activeMatrixId == 2)
      />
      <GridSelectItem
        onClick=(_ => onGridSelectItemClick(3))
        isActive=(activeMatrixId == 3)
      />
    </div>
  }
};
