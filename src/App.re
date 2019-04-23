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
    <div className=Styles.app>
      <Intro
        isIntroVisible=state.showIntro
        onShowHideClick=(_ => send(UpdateShowIntro(!state.showIntro)))
      />
      <div className=Styles.buttonsContainer>
        <div className=Styles.buttons>
          <RepeatButton
            isActive=state.repeat
            onClick=(_ => send(UpdateRepeat(!state.repeat)))
          />
          <TrainButton
            onClick=(_ => send(Train))
          />
          <StateSizeSelect
            onClick=((size, _) => send(UpdateSize(size)))
            size=state.size
          />
          <PlayGeneratedButton
            isActive=state.playGenerated
            onClick=(_ => send(UpdatePlayGenerated(!state.playGenerated)))
          />
        </div>
      </div>
      {switch (state.playGenerated) {
      | false =>
      <Grid
        matrix=state.matrix[state.activeMatrixId]
        onDotClick=((x, y) => switch(state.playGenerated) {
          | true => ()
          | false => send(UpdateMatrixPoint(x, y))
          })
        playingRow=state.playingRow
        isGenerated=false
      />
      | true =>
      <Grid
        matrix=state.generatedMattrix[state.activeMatrixId]
        onDotClick=((_, _) => ())
        playingRow=state.playingRow
        isGenerated=true
      />
      }}
      <GridSelect
        activeMatrixId=state.activeMatrixId
        onGridSelectItemClick=(id => send(UpdateActiveMatrix(id)))
      />
    </div>
};
