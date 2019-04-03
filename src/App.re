open Store;

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  initialState,
  reducer,
  didMount: self => {
    let intervalId = Js.Global.setInterval(() => self.send(Tick), 300);
    let _ = Js.Global.setTimeout(() => self.send(Init(intervalId)), 300);
  },
  willUnmount: self => {
    self.send(Shutdown);
  },
  render: ({ state, send }) =>
    <div>
      <RepeatButton
        isActive=state.repeat
        onClick=(_ => send(UpdateRepeat(!state.repeat)))
      />
      <TrainButton
        onClick=(_ => send(Train))
      />
      <PlayGeneratedButton
        isActive=state.playGenerated
        onClick=(_ => send(UpdatePlayGenerated(!state.playGenerated)))
      />
      {switch (state.playGenerated) {
      | false =>
      <Grid
        matrix=state.matrix[state.activeMatrixId]
        onDotClick=((x, y) => send(UpdateMatrixPoint(x, y)))
        playingRow=state.playingRow
      />
      | true =>
      <Grid
        matrix=state.generatedMattrix[state.activeMatrixId]
        onDotClick=((_, _) => ())
        playingRow=state.playingRow
      />
      }}
      <GridSelect
        activeMatrixId=state.activeMatrixId
        onGridSelectItemClick=(id => send(UpdateActiveMatrix(id)))
      />
    </div>
};
