open Css;

let app = style([
  fontFamily("sans-serif"),
  maxWidth(px(500)),
  margin(auto),
  marginBottom(px(40)),
  position(relative)
]);

let grid = style([
  display(grid),
  gridTemplateColumns([pct(12.0), pct(12.0), pct(12.0), pct(12.0), pct(12.0), pct(12.0), pct(12.0), pct(12.0)]),
  gridTemplateRows([pct(12.0), pct(12.0), pct(12.0), pct(12.0), pct(12.0), pct(12.0), pct(12.0)]),
  gridColumnGap(pct(0.5)),
  gridRowGap(pct(0.5)),
  position(absolute),
  width(pct(100.0)),
  height(pct(100.0)),
]);

let gridSpacing = style([
  paddingBottom(pct(100.0))
]);

let gridContainer = style([
  position(relative),
  maxWidth(px(500))
]);

let dot = style([
  backgroundColor(blue),
  border(px(1), solid, black)
]);

let dotGenerated = style([
  backgroundColor(lightblue),
  border(px(1), solid, darkgrey)
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

let gridSelectContainer = style([
  maxWidth(px(500)),
  marginTop(px(-40)),
  position(relative)
]);

let gridSelect = style([
  display(flexBox),
  flexDirection(row),
  justifyContent(spaceAround),
  maxWidth(px(400)),
  width(pct(100.0)),
  marginLeft(auto),
  marginRight(auto)
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

let buttonsContainer = style([
  maxWidth(px(500))
]);

let buttons = style([
  display(flexBox),
  justifyContent(spaceAround),
  marginBottom(px(20)),
  marginTop(px(20))
]);

let button = style([
  width(pct(22.0)),
  outline(px(0), solid, transparent),
  border(px(4), solid, darkgrey),
  padding(px(4)),
  textAlign(center)
]);

let buttonActive = merge([
  button,
  style([
    borderColor(orange),
  ])
]);

let buttonDown = merge([
  button,
  style([
    backgroundColor(darkgrey)
  ])
]);

let stateSizeSelectContainer = style([
  width(pct(22.0))
]);

let stateSizeText = style([
  fontSize(px(12)),
  textAlign(center),
  lineHeight(px(16))
]);

let stateSizeSelect = style([
  width(pct(100.0)),
  display(flexBox),
  justifyContent(spaceAround),
  border(px(4), solid, darkgrey),
  boxSizing(borderBox)
]);

let stateSizeSelectButton = merge([
  button,
  style([
    height(px(25)),
    width(pct(25.0)),
    border(px(0), solid, transparent)
  ])
]);

let stateSizeSelectButtonActive = merge([
  stateSizeSelectButton,
  style([
    backgroundColor(orange)
  ])
]);

let introButton = merge([
  button,
  style([
    width(auto),
    backgroundColor(transparent),
    border(px(0), solid, transparent),
    textDecoration(underline),
    position(absolute),
    top(px(13)),
    right(px(3)),
    color(hex("a5a5a5")),
    letterSpacing(pxFloat(0.25)),
    fontWeight(bold)
  ])
]);

let repeatButton = button;
let repeatButtonActive = buttonActive;
let playGeneratedButton = button;
let playGeneratedButtonActive = buttonActive;
let muteButton = button;
let muteButtonActive = buttonActive;
let trainButton = button;
