let component = ReasonReact.statelessComponent("Grid");

let rec makeDots = (onDotClick, playingRow, matrix, dots, x, y) => {
  let content = string_of_int(7-x) ++ "." ++ string_of_int(6-y);
  switch (y < 7) {
    | true =>
      makeDots(
        onDotClick,
        playingRow,
        matrix,
        [
          <Dot
            onClick=(() => onDotClick(7-x, 6-y))
            isActive=(matrix[7-x][6-y] == 1)
            isPlaying=(7-x == playingRow)
            content=content
          />,
          ...dots
        ],
        x == 7 ? 0 : x+1,
        x == 7 ? y+1 : y
      )
    | false =>
        dots
    };
};

let make = (~onDotClick, ~matrix, ~playingRow, _children) => {
  ...component,
  render: _self => {
    let dots = makeDots(
      onDotClick,
      playingRow,
      matrix,
      [],
      0,
      0
    );
    <div className=Styles.grid>
      {ReasonReact.array(Array.of_list(dots))}
    </div>
  }
};
