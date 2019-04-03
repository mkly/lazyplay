type state = {
  matrix: array(array(array(int))),
  generatedMattrix: array(array(array(int))),
  activeMatrixId: int,
  playGenerated: bool,
  repeat: bool,
  playingRow: int,
  intervalId: Js.Nullable.t(Js.Global.intervalId)
};

let initialState = () => {
  matrix: [| 
    [|
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|]
    |],
    [|
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|]
    |],
    [|
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|]
    |],
    [|
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|]
    |]
  |],
  activeMatrixId: 0,
  generatedMattrix: [|
    [|
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|]
    |],
    [|
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|]
    |],
    [|
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|]
    |],
    [|
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|],
      [|0,0,0,0,0,0,0|]
    |]
  |],
  playingRow: 0,
  playGenerated: false,
  repeat: true,
  intervalId: Js.Nullable.null
};
type action =
  | Tick
  | UpdateActiveMatrix(int)
  | IncrementActiveMatrix
  | UpdateMatrixPoint(int,int)
  | UpdateRepeat(bool)
  | UpdatePlayGenerated(bool)
  | Train
  | Init(Js.Global.intervalId)
  | Shutdown

let reducer = (action, state) =>
  switch (action) {
  | UpdateActiveMatrix(id) =>
    ReasonReact.Update({
      ...state,
      activeMatrixId: id
    });
  | IncrementActiveMatrix =>
    ReasonReact.Update({
      ...state,
      activeMatrixId: state.activeMatrixId > 3 ? 0 : state.activeMatrixId + 1
    });
  | UpdateMatrixPoint(x,y) =>
    let matrix = state.matrix;
    matrix[state.activeMatrixId][x][y] = matrix[state.activeMatrixId][x][y] > 0 ? 0 : 1;
    ReasonReact.Update({
      ...state,
      matrix
    });
  | UpdateRepeat(repeat) =>
    ReasonReact.Update({
      ...state,
      repeat 
    });
  | UpdatePlayGenerated(playGenerated) =>
    ReasonReact.Update({
      ...state,
      playGenerated
    });
  | Train =>
    let generatedMattrix = Train.train(Array.to_list(state.matrix));
    ReasonReact.Update({
      ...state,
      generatedMattrix
    });
  | Tick =>
    let playingRow =
      switch (state.playingRow > 6) {
        | true => 0
        | false => state.playingRow + 1
        };
    let id =
      switch (state.repeat) {
        | false => state.activeMatrixId
        | true => switch (playingRow == 0) {
          | false => state.activeMatrixId
          | true => state.activeMatrixId == 3 ? 0 : state.activeMatrixId + 1
          }
        };
      Synth.playNote(
        state.playGenerated ? state.generatedMattrix[id][playingRow] : state.matrix[id][playingRow],
        0.3
      );
    switch (state.playGenerated) {
      | true =>
        Synth.playNote(state.generatedMattrix[id][playingRow], 0.05);
      | false =>
        Synth.playNote(state.matrix[id][playingRow], 0.05);
    };
    ReasonReact.Update({
      ...state,
      playingRow,
      activeMatrixId: id
    });
  | Init(intervalId) => 
    ReasonReact.Update({
      ...state,
      intervalId: Js.Nullable.return(intervalId)
    });
  | Shutdown =>
    switch(Js.Nullable.toOption(state.intervalId)) {
      | Some(id) => Js.Global.clearInterval(id)
      | None => ()
      };

    ReasonReact.Update({
      ...state,
      intervalId: Js.Nullable.null
    });
  };
