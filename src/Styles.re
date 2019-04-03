open Css;

let grid = style([
  display(grid),
  gridTemplateColumns([px(50), px(50), px(50), px(50), px(50), px(50), px(50), px(50)]),
  gridTemplateRows([px(50), px(50), px(50), px(50), px(50), px(50), px(50)]),
  gridColumnGap(px(6)),
  gridRowGap(px(6))
]);

let dot = style([
  backgroundColor(blue),
  border(px(1), solid, black)
]);

let dotActive = merge([
  dot,
  style([
    backgroundColor(orange)
  ])
]);

let dotPlaying = merge([
  dotActive,
  style([
    backgroundColor(pink)
  ])
]);

let dotPlayingAndActive = merge([
  dotPlaying,
  style([
    backgroundColor(green)
  ])
]);

let gridSelect = style([
  display(flexBox),
  flexDirection(row),
  justifyContent(center),
  width(px(400)),
  marginTop(px(20))
]);

let gridSelectItem = style([
  backgroundColor(grey),
  color(white),
  height(px(65)),
  width(px(65)),
  margin(px(3)),
  border(px(1), solid, black)
]);

let gridSelectItemActive = merge([
  gridSelectItem,
  style([
    backgroundColor(orange)
  ])
]);

let repeatButton = style([
  backgroundColor(grey),
  border(px(1), solid, darkgrey),
  width(px(140)),
  height(px(40)),
  marginBottom(px(10))
]);

let repeatButtonActive = merge([
  repeatButton,
  style([
    backgroundColor(red),
    color(white),
    border(px(1), solid, darkred)
  ])
]);

let playGeneratedButton = style([
  backgroundColor(grey),
  border(px(1), solid, darkgrey),
  width(px(140)),
  height(px(40)),
  marginBottom(px(10))
]);

let playGeneratedButtonActive = merge([
  playGeneratedButton,
  style([
    backgroundColor(olive),
    color(white),
    border(px(1), solid, white)
  ])
]);

let muteButton = style([
  backgroundColor(grey),
  border(px(1), solid, darkgrey),
  width(px(140)),
  height(px(40)),
  marginBottom(px(10))
]);

let muteButtonActive = merge([
  playGeneratedButton,
  style([
    backgroundColor(olive),
    color(white),
    border(px(1), solid, white)
  ])
]);

let trainButton = style([
  backgroundColor(purple),
  color(white),
  border(px(1), solid, goldenrod),
  width(px(140)),
  height(px(40)),
  marginBottom(px(40))
]);
