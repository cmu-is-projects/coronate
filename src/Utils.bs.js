// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Cn from "re-classnames/src/Cn.bs.js";
import * as Css from "bs-css/src/Css.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as Ramda from "ramda";
import * as React from "react";
import * as Nanoid from "nanoid";
import * as Numeral from "@johnridesabike/bs-numeral/src/Numeral.bs.js";
import * as Belt_List from "bs-platform/lib/es6/belt_List.js";
import * as Caml_array from "bs-platform/lib/es6/caml_array.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as ReactFeather from "react-feather";
import * as ReasonReactRouter from "reason-react/src/ReasonReactRouter.js";
import * as Externals$Coronate from "./Externals.bs.js";

function splitAt(prim, prim$1) {
  return Ramda.splitAt(prim, prim$1);
}

function descend(prim, prim$1, prim$2) {
  return Ramda.descend(prim, prim$1, prim$2);
}

function ascend(prim, prim$1, prim$2) {
  return Ramda.ascend(prim, prim$1, prim$2);
}

function alert(prim) {
  window.alert(prim);
  return /* () */0;
}

function nanoid(prim) {
  return Nanoid.default();
}

function absf(prim) {
  return Math.abs(prim);
}

function sortWith(prim, prim$1) {
  return Ramda.sortWith(prim, prim$1);
}

function sortWithF(prim, prim$1) {
  return Ramda.sortWith(prim, prim$1);
}

function confirm(prim) {
  return window.confirm(prim);
}

function move(prim, prim$1, prim$2) {
  return Ramda.move(prim, prim$1, prim$2);
}

function add(a, b) {
  return a + b | 0;
}

function arraySum(arr) {
  return arr.reduce(add, 0);
}

function addFloat(a, b) {
  return a + b;
}

function arraySumFloat(arr) {
  return arr.reduce(addFloat, 0.0);
}

function listSumFloat(list) {
  return Belt_List.reduce(list, 0.0, addFloat);
}

function last(arr) {
  return Caml_array.caml_array_get(arr, arr.length - 1 | 0);
}

function splitInHalf(arr) {
  return Ramda.splitAt(arr.length / 2 | 0, arr);
}

var logo = ( require("./assets/icon-min.svg") );

var caution = ( require("./assets/caution.svg") );

var WebpackAssets = /* module */[
  /* logo */logo,
  /* caution */caution
];

var Entities = /* module */[
  /* nbsp */"\xa0",
  /* copy */"\xa9"
];

function listToReactArray(list, func) {
  return Belt_List.reduce(list, /* array */[], (function (acc, item) {
                return acc.concat(/* array */[Curry._1(func, item)]);
              }));
}

function DateTimeFormatComponent(Config) {
  var dtobj = new Intl.DateTimeFormat(Externals$Coronate.IntlDateTimeFormat[/* string_of_locale */0](Config[/* locale */0]), Config[/* config */1]);
  var Utils$DateTimeFormatComponent = function (Props) {
    var date = Props.date;
    return React.createElement("time", {
                dateTime: date.toISOString()
              }, dtobj.format(date));
  };
  return /* module */[
          /* IDTF */0,
          /* dtobj */dtobj,
          /* make */Utils$DateTimeFormatComponent
        ];
}

var config = Externals$Coronate.IntlDateTimeFormat[/* config */4](/* two_digit */156521338, /* short */-64519044, /* numeric */734061261, undefined, undefined, /* () */0);

var dtobj = new Intl.DateTimeFormat(Externals$Coronate.IntlDateTimeFormat[/* string_of_locale */0](/* en_us */-260666444), config);

function Utils$DateTimeFormatComponent(Props) {
  var date = Props.date;
  return React.createElement("time", {
              dateTime: date.toISOString()
            }, dtobj.format(date));
}

var DateFormat = /* module */[
  /* IDTF */0,
  /* dtobj */dtobj,
  /* make */Utils$DateTimeFormatComponent
];

var config$1 = Externals$Coronate.IntlDateTimeFormat[/* config */4](/* two_digit */156521338, /* short */-64519044, /* numeric */734061261, /* two_digit */156521338, /* two_digit */156521338, /* () */0);

var dtobj$1 = new Intl.DateTimeFormat(Externals$Coronate.IntlDateTimeFormat[/* string_of_locale */0](/* en_us */-260666444), config$1);

function Utils$DateTimeFormatComponent$1(Props) {
  var date = Props.date;
  return React.createElement("time", {
              dateTime: date.toISOString()
            }, dtobj$1.format(date));
}

var DateTimeFormat = /* module */[
  /* IDTF */0,
  /* dtobj */dtobj$1,
  /* make */Utils$DateTimeFormatComponent$1
];

var panels = Css.style(/* :: */[
      Css.display(/* flex */-1010954439),
      /* :: */[
        Css.flexWrap(/* wrap */-822134326),
        /* :: */[
          Css.media("screen and (min-width: 600px)", /* :: */[
                Css.flexWrap(/* nowrap */867913355),
                /* [] */0
              ]),
          /* [] */0
        ]
      ]
    ]);

var panel = Css.style(/* :: */[
      Css.marginRight(/* `px */[
            25096,
            16
          ]),
      /* [] */0
    ]);

var Style = /* module */[
  /* panels */panels,
  /* panel */panel
];

function Utils$Panel(Props) {
  var children = Props.children;
  var match = Props.className;
  var className = match !== undefined ? match : "";
  var match$1 = Props.style;
  var style = match$1 !== undefined ? Caml_option.valFromOption(match$1) : { };
  return React.createElement("div", {
              className: Cn.make(/* :: */[
                    panel,
                    /* :: */[
                      className,
                      /* [] */0
                    ]
                  ]),
              style: style
            }, children);
}

var Panel = /* module */[/* make */Utils$Panel];

function Utils$PanelContainer(Props) {
  var children = Props.children;
  var match = Props.className;
  var className = match !== undefined ? match : "";
  var match$1 = Props.style;
  var style = match$1 !== undefined ? Caml_option.valFromOption(match$1) : { };
  return React.createElement("div", {
              className: Cn.make(/* :: */[
                    panels,
                    /* :: */[
                      className,
                      /* [] */0
                    ]
                  ]),
              style: style
            }, children);
}

var PanelContainer = /* module */[/* make */Utils$PanelContainer];

var green_50 = /* `hex */[
  5194459,
  "30e60b"
];

var green_90 = /* `hex */[
  5194459,
  "003706"
];

var yellow_50 = /* `hex */[
  5194459,
  "ffe900"
];

var yellow_90 = /* `hex */[
  5194459,
  "3e2800"
];

var red_60 = /* `hex */[
  5194459,
  "d70022"
];

var white_100 = /* `hex */[
  5194459,
  "ffffff"
];

var PhotonColors_000 = /* magenta_50 : `hex */[
  5194459,
  "ff1ad9"
];

var PhotonColors_001 = /* magenta_60 : `hex */[
  5194459,
  "ed00b5"
];

var PhotonColors_002 = /* magenta_70 : `hex */[
  5194459,
  "b5007f"
];

var PhotonColors_003 = /* magenta_80 : `hex */[
  5194459,
  "7d004f"
];

var PhotonColors_004 = /* magenta_90 : `hex */[
  5194459,
  "440027"
];

var PhotonColors_005 = /* purple_30 : `hex */[
  5194459,
  "c069ff"
];

var PhotonColors_006 = /* purple_40 : `hex */[
  5194459,
  "ad3bff"
];

var PhotonColors_007 = /* purple_50 : `hex */[
  5194459,
  "9400ff"
];

var PhotonColors_008 = /* purple_60 : `hex */[
  5194459,
  "8000d7"
];

var PhotonColors_009 = /* purple_70 : `hex */[
  5194459,
  "6200a4"
];

var PhotonColors_010 = /* purple_80 : `hex */[
  5194459,
  "440071"
];

var PhotonColors_011 = /* purple_90 : `hex */[
  5194459,
  "25003e"
];

var PhotonColors_012 = /* blue_40 : `hex */[
  5194459,
  "45a1ff"
];

var PhotonColors_013 = /* blue_50 : `hex */[
  5194459,
  "0a84ff"
];

var PhotonColors_014 = /* blue_50_A30 : `hex */[
  5194459,
  "0a84ff4c"
];

var PhotonColors_015 = /* blue_60 : `hex */[
  5194459,
  "0060df"
];

var PhotonColors_016 = /* blue_70 : `hex */[
  5194459,
  "003eaa"
];

var PhotonColors_017 = /* blue_80 : `hex */[
  5194459,
  "002275"
];

var PhotonColors_018 = /* blue_90 : `hex */[
  5194459,
  "000f40"
];

var PhotonColors_019 = /* teal_50 : `hex */[
  5194459,
  "00feff"
];

var PhotonColors_020 = /* teal_60 : `hex */[
  5194459,
  "00c8d7"
];

var PhotonColors_021 = /* teal_70 : `hex */[
  5194459,
  "008ea4"
];

var PhotonColors_022 = /* teal_80 : `hex */[
  5194459,
  "005a71"
];

var PhotonColors_023 = /* teal_90 : `hex */[
  5194459,
  "002d3e"
];

var PhotonColors_025 = /* green_60 : `hex */[
  5194459,
  "12bc00"
];

var PhotonColors_026 = /* green_70 : `hex */[
  5194459,
  "058b00"
];

var PhotonColors_027 = /* green_80 : `hex */[
  5194459,
  "006504"
];

var PhotonColors_030 = /* yellow_60 : `hex */[
  5194459,
  "d7b600"
];

var PhotonColors_031 = /* yellow_70 : `hex */[
  5194459,
  "a47f00"
];

var PhotonColors_032 = /* yellow_80 : `hex */[
  5194459,
  "715100"
];

var PhotonColors_034 = /* red_50 : `hex */[
  5194459,
  "ff0039"
];

var PhotonColors_036 = /* red_70 : `hex */[
  5194459,
  "a4000f"
];

var PhotonColors_037 = /* red_80 : `hex */[
  5194459,
  "5a0002"
];

var PhotonColors_038 = /* red_90 : `hex */[
  5194459,
  "3e0200"
];

var PhotonColors_039 = /* orange_50 : `hex */[
  5194459,
  "ff9400"
];

var PhotonColors_040 = /* orange_60 : `hex */[
  5194459,
  "d76e00"
];

var PhotonColors_041 = /* orange_70 : `hex */[
  5194459,
  "a44900"
];

var PhotonColors_042 = /* orange_80 : `hex */[
  5194459,
  "712b00"
];

var PhotonColors_043 = /* orange_90 : `hex */[
  5194459,
  "3e1300"
];

var PhotonColors_044 = /* grey_10 : `hex */[
  5194459,
  "f9f9fa"
];

var PhotonColors_045 = /* grey_10_A10 : `hex */[
  5194459,
  "f9f9fa19"
];

var PhotonColors_046 = /* grey_10_A20 : `hex */[
  5194459,
  "f9f9fa33"
];

var PhotonColors_047 = /* grey_10_A40 : `hex */[
  5194459,
  "f9f9fa66"
];

var PhotonColors_048 = /* grey_10_A60 : `hex */[
  5194459,
  "f9f9fa99"
];

var PhotonColors_049 = /* grey_10_A80 : `hex */[
  5194459,
  "f9f9facc"
];

var PhotonColors_050 = /* grey_20 : `hex */[
  5194459,
  "ededf0"
];

var PhotonColors_051 = /* grey_30 : `hex */[
  5194459,
  "d7d7db"
];

var PhotonColors_052 = /* grey_40 : `hex */[
  5194459,
  "b1b1b3"
];

var PhotonColors_053 = /* grey_50 : `hex */[
  5194459,
  "737373"
];

var PhotonColors_054 = /* grey_60 : `hex */[
  5194459,
  "4a4a4f"
];

var PhotonColors_055 = /* grey_70 : `hex */[
  5194459,
  "38383d"
];

var PhotonColors_056 = /* grey_80 : `hex */[
  5194459,
  "2a2a2e"
];

var PhotonColors_057 = /* grey_90 : `hex */[
  5194459,
  "0c0c0d"
];

var PhotonColors_058 = /* grey_90_A05 : `hex */[
  5194459,
  "0c0c0d0c"
];

var PhotonColors_059 = /* grey_90_A10 : `hex */[
  5194459,
  "0c0c0d19"
];

var PhotonColors_060 = /* grey_90_A20 : `hex */[
  5194459,
  "0c0c0d33"
];

var PhotonColors_061 = /* grey_90_A30 : `hex */[
  5194459,
  "0c0c0d4c"
];

var PhotonColors_062 = /* grey_90_A40 : `hex */[
  5194459,
  "0c0c0d66"
];

var PhotonColors_063 = /* grey_90_A50 : `hex */[
  5194459,
  "0c0c0d7f"
];

var PhotonColors_064 = /* grey_90_A60 : `hex */[
  5194459,
  "0c0c0d99"
];

var PhotonColors_065 = /* grey_90_A70 : `hex */[
  5194459,
  "0c0c0db2"
];

var PhotonColors_066 = /* grey_90_A80 : `hex */[
  5194459,
  "0c0c0dcc"
];

var PhotonColors_067 = /* grey_90_A90 : `hex */[
  5194459,
  "0c0c0de5"
];

var PhotonColors_068 = /* ink_70 : `hex */[
  5194459,
  "363959"
];

var PhotonColors_069 = /* ink_80 : `hex */[
  5194459,
  "202340"
];

var PhotonColors_070 = /* ink_90 : `hex */[
  5194459,
  "0f1126"
];

var PhotonColors = /* module */[
  PhotonColors_000,
  PhotonColors_001,
  PhotonColors_002,
  PhotonColors_003,
  PhotonColors_004,
  PhotonColors_005,
  PhotonColors_006,
  PhotonColors_007,
  PhotonColors_008,
  PhotonColors_009,
  PhotonColors_010,
  PhotonColors_011,
  PhotonColors_012,
  PhotonColors_013,
  PhotonColors_014,
  PhotonColors_015,
  PhotonColors_016,
  PhotonColors_017,
  PhotonColors_018,
  PhotonColors_019,
  PhotonColors_020,
  PhotonColors_021,
  PhotonColors_022,
  PhotonColors_023,
  /* green_50 */green_50,
  PhotonColors_025,
  PhotonColors_026,
  PhotonColors_027,
  /* green_90 */green_90,
  /* yellow_50 */yellow_50,
  PhotonColors_030,
  PhotonColors_031,
  PhotonColors_032,
  /* yellow_90 */yellow_90,
  PhotonColors_034,
  /* red_60 */red_60,
  PhotonColors_036,
  PhotonColors_037,
  PhotonColors_038,
  PhotonColors_039,
  PhotonColors_040,
  PhotonColors_041,
  PhotonColors_042,
  PhotonColors_043,
  PhotonColors_044,
  PhotonColors_045,
  PhotonColors_046,
  PhotonColors_047,
  PhotonColors_048,
  PhotonColors_049,
  PhotonColors_050,
  PhotonColors_051,
  PhotonColors_052,
  PhotonColors_053,
  PhotonColors_054,
  PhotonColors_055,
  PhotonColors_056,
  PhotonColors_057,
  PhotonColors_058,
  PhotonColors_059,
  PhotonColors_060,
  PhotonColors_061,
  PhotonColors_062,
  PhotonColors_063,
  PhotonColors_064,
  PhotonColors_065,
  PhotonColors_066,
  PhotonColors_067,
  PhotonColors_068,
  PhotonColors_069,
  PhotonColors_070,
  /* white_100 */white_100
];

var container = Css.style(/* :: */[
      Css.display(/* flex */-1010954439),
      /* :: */[
        Css.flexDirection(/* row */5693978),
        /* :: */[
          Css.justifyContent(/* center */98248149),
          /* :: */[
            Css.minHeight(/* `px */[
                  25096,
                  32
                ]),
            /* :: */[
              Css.fontSize(/* `px */[
                    25096,
                    13
                  ]),
              /* :: */[
                Css.fontWeight(/* `num */[
                      5496390,
                      400
                    ]),
                /* :: */[
                  Css.paddingTop(/* `px */[
                        25096,
                        4
                      ]),
                  /* :: */[
                    Css.paddingBottom(/* `px */[
                          25096,
                          4
                        ]),
                    /* :: */[
                      Css.margin2(/* `px */[
                            25096,
                            4
                          ], /* zero */-789508312),
                      /* :: */[
                        Css.borderRadius(/* `px */[
                              25096,
                              4
                            ]),
                        /* [] */0
                      ]
                    ]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
    ]);

var text = Css.style(/* :: */[
      Css.display(/* flex */-1010954439),
      /* :: */[
        Css.flexDirection(/* row */5693978),
        /* :: */[
          Css.alignItems(/* center */98248149),
          /* [] */0
        ]
      ]
    ]);

var icon = Css.style(/* :: */[
      Css.display(/* flex */-1010954439),
      /* :: */[
        Css.flexDirection(/* row */5693978),
        /* :: */[
          Css.alignItems(/* center */98248149),
          /* :: */[
            Css.flexShrink(1.0),
            /* :: */[
              Css.margin2(/* zero */-789508312, /* `px */[
                    25096,
                    4
                  ]),
              /* :: */[
                Css.fontSize(/* `px */[
                      25096,
                      16
                    ]),
                /* :: */[
                  Css.cursor(/* help */-989121855),
                  /* [] */0
                ]
              ]
            ]
          ]
        ]
      ]
    ]);

var success = Css.style(/* :: */[
      Css.color(green_90),
      /* :: */[
        Css.backgroundColor(green_50),
        /* [] */0
      ]
    ]);

var warning = Css.style(/* :: */[
      Css.color(yellow_90),
      /* :: */[
        Css.backgroundColor(yellow_50),
        /* [] */0
      ]
    ]);

var error = Css.style(/* :: */[
      Css.color(white_100),
      /* :: */[
        Css.backgroundColor(red_60),
        /* [] */0
      ]
    ]);

var Style$1 = /* module */[
  /* container */container,
  /* text */text,
  /* icon */icon,
  /* success */success,
  /* warning */warning,
  /* error */error
];

function Utils$Notification(Props) {
  var children = Props.children;
  var match = Props.kind;
  var kind = match !== undefined ? match : /* Generic */3;
  var match$1 = Props.tooltip;
  var tooltip = match$1 !== undefined ? match$1 : "";
  var match$2 = Props.className;
  var className = match$2 !== undefined ? match$2 : "";
  var match$3 = Props.style;
  var style = match$3 !== undefined ? Caml_option.valFromOption(match$3) : { };
  var match$4;
  switch (kind) {
    case 0 : 
        match$4 = /* tuple */[
          React.createElement(ReactFeather.Check, { }),
          success
        ];
        break;
    case 1 : 
        match$4 = /* tuple */[
          React.createElement(ReactFeather.AlertTriangle, { }),
          warning
        ];
        break;
    case 2 : 
        match$4 = /* tuple */[
          React.createElement(ReactFeather.X, { }),
          error
        ];
        break;
    case 3 : 
        match$4 = /* tuple */[
          React.createElement(ReactFeather.Info, { }),
          ""
        ];
        break;
    
  }
  return React.createElement("div", {
              className: Cn.make(/* :: */[
                    container,
                    /* :: */[
                      match$4[1],
                      /* :: */[
                        className,
                        /* [] */0
                      ]
                    ]
                  ]),
              style: style
            }, React.createElement("div", {
                  "aria-label": tooltip,
                  className: icon,
                  title: tooltip
                }, match$4[0]), React.createElement("div", {
                  className: text
                }, children));
}

var $$Notification = /* module */[
  /* Style */Style$1,
  /* make */Utils$Notification
];

function hashPath(hashString) {
  return Belt_List.fromArray(hashString.split("/"));
}

function Utils$Router$HashLink(Props) {
  var children = Props.children;
  var to_ = Props.to_;
  var onDragStart = Props.onDragStart;
  var match = ReasonReactRouter.useUrl(undefined, /* () */0);
  var hash = match[/* hash */1];
  var isCurrent = to_ === "/" ? hash === "" || hash === to_ : hash === to_;
  var ariaCurrent = isCurrent ? "true" : "false";
  return React.createElement("a", {
              "aria-current": ariaCurrent,
              href: "#" + to_,
              onDragStart: onDragStart
            }, children);
}

var HashLink = /* module */[/* make */Utils$Router$HashLink];

var Router = /* module */[
  /* hashPath */hashPath,
  /* HashLink */HashLink
];

Numeral.registerFormat("fraction", {
      format: (function (value, _format, _roundingFunction) {
          var whole = Math.floor(value);
          var remainder = value - whole;
          var fraction = remainder !== 0.25 ? (
              remainder !== 0.5 ? (
                  remainder !== 0.75 ? "" : "¾"
                ) : "½"
            ) : "¼";
          var match = whole === 0.0 && fraction !== "";
          var stringedWhole = match ? "" : whole.toString();
          return stringedWhole + fraction;
        }),
      regexps: {
        format: (/(1\/2)/),
        unformat: (/(1\/2)/)
      },
      unformat: (function (value) {
          return Number(value);
        })
    });

var Tabs = 0;

var VisuallyHidden = 0;

var Dialog = 0;

var github_url = "https://github.com/johnridesabike/coronate";

var license_url = "https://github.com/johnridesabike/coronate/blob/master/LICENSE";

var issues_url = "https://github.com/johnridesabike/coronate/issues/new";

export {
  Tabs ,
  VisuallyHidden ,
  Dialog ,
  splitAt ,
  descend ,
  ascend ,
  alert ,
  nanoid ,
  absf ,
  sortWith ,
  sortWithF ,
  confirm ,
  move ,
  add ,
  arraySum ,
  addFloat ,
  arraySumFloat ,
  listSumFloat ,
  last ,
  splitInHalf ,
  github_url ,
  license_url ,
  issues_url ,
  WebpackAssets ,
  Entities ,
  listToReactArray ,
  DateTimeFormatComponent ,
  DateFormat ,
  DateTimeFormat ,
  Style ,
  Panel ,
  PanelContainer ,
  PhotonColors ,
  $$Notification ,
  Router ,
  
}
/* logo Not a pure module */
