let component = ReasonReact.statelessComponent("StateSizeSelect");

let getClass = (idx, size) =>
  switch (idx == size) {
    | true => Styles.stateSizeSelectButtonActive
    | false => Styles.stateSizeSelectButton
    };

let make = (~size, ~onClick, _children) => {
  ...component,
  render: _self => {
    <div className=Styles.stateSizeSelectContainer>
      <div className=Styles.stateSizeText>{ReasonReact.string("State Size")}</div>
      <div className=Styles.stateSizeSelect>
        <Button className=getClass(1, size) onClick=onClick(1)>...{ReasonReact.string("1")}</Button>
        <Button className=getClass(2, size) onClick=onClick(2)>...{ReasonReact.string("2")}</Button>
        <Button className=getClass(3, size) onClick=onClick(3)>...{ReasonReact.string("3")}</Button>
        <Button className=getClass(4, size) onClick=onClick(4)>...{ReasonReact.string("4")}</Button>
      </div>
    </div>
  }
};
