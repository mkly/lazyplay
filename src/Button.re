type state = {
  mouseDown: bool
}

type action =
  | Active
  | InActive

let component = ReasonReact.reducerComponent("BButton");

let make = (~className, ~onClick, _children) => {
  ...component,
  initialState: () => {
    mouseDown: false
  },
  reducer: (action, state) =>
    switch (action) {
      | Active => ReasonReact.Update({...state, mouseDown: true })
      | InActive => ReasonReact.Update({...state, mouseDown: false })
    },
  render: self => {
    Js.log(self.state)
    let newClassName =
      switch (self.state.mouseDown) {
        | true => String.concat(" ", [className, Styles.buttonDown])
        | _ => className
      };
    <button
      onClick
      className=newClassName
      onMouseDown=(_ => self.send(Active))
      onMouseUp=(_ => self.send(InActive))
      onMouseOut=(_ => self.send(InActive))
      onMouseLeave=(_ => self.send(InActive))
      onTouchStart=(_ => self.send(Active))
      onTouchEnd=(_ => self.send(InActive))
      onTouchCancel=(_ => self.send(InActive))
    >
      {_children}
    </button>
  }
}
