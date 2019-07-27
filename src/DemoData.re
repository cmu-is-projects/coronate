open Data;
open Belt;
let config =
  Config.{
    byeValue: ByeValue.Full,
    avoidPairs:
      Set.fromArray(
        [|
          ("BarbaraGordon_cL6SpI2", "JamesGordon_1ts9xICT3"),
          ("Joker_v0z2416fpAZ9o2c", "HarleyQuinn_-10-02VPH"),
          ("HelenaWayne_fE6O0DJcE", "BruceWayne_lv_ZsUHTU9"),
        |],
        ~id=(module AvoidPairs.T),
      ),
    lastBackup: Js.Date.fromString("1970-01-01T00:00:00.000Z"),
  };

let players =
  Map.String.fromArray([|
    (
      "BruceWayne_lv_ZsUHTU9",
      Player.{
        id: "BruceWayne_lv_ZsUHTU9",
        type_: Player.Type.Person,
        firstName: "Bruce",
        lastName: "Wayne",
        rating: 1998,
        matchCount: 9,
      },
    ),
    (
      "DickGrayson_1C2rCokHH",
      {
        id: "DickGrayson_1C2rCokHH",
        type_: Player.Type.Person,
        firstName: "Dick",
        lastName: "Grayson",
        rating: 1909,
        matchCount: 9,
      },
    ),
    (
      "AlfredPennyworth_y4dW",
      {
        id: "AlfredPennyworth_y4dW",
        type_: Player.Type.Person,
        firstName: "Alfred",
        lastName: "Pennyworth",
        rating: 1999,
        matchCount: 9,
      },
    ),
    (
      "BarbaraGordon_cL6SpI2",
      {
        id: "BarbaraGordon_cL6SpI2",
        type_: Player.Type.Person,
        firstName: "Barbara",
        lastName: "Gordon",
        rating: 1345,
        matchCount: 7,
      },
    ),
    (
      "KateKane_klFW6gDfUOTX",
      {
        id: "KateKane_klFW6gDfUOTX",
        type_: Player.Type.Person,
        firstName: "Kate",
        lastName: "Kane",
        rating: 1539,
        matchCount: 9,
      },
    ),
    (
      "SelinaKyle_rJBH-45Xoy",
      {
        id: "SelinaKyle_rJBH-45Xoy",
        type_: Player.Type.Person,
        firstName: "Selina",
        lastName: "Kyle",
        rating: 1495,
        matchCount: 9,
      },
    ),
    (
      "JasonTodd_fc9CeOa-Luw",
      {
        id: "JasonTodd_fc9CeOa-Luw",
        type_: Player.Type.Person,
        firstName: "Jason",
        lastName: "Todd",
        rating: 1101,
        matchCount: 7,
      },
    ),
    (
      "JamesGordon_1ts9xICT3",
      {
        id: "JamesGordon_1ts9xICT3",
        type_: Player.Type.Person,
        firstName: "James",
        lastName: "Gordon",
        rating: 1167,
        matchCount: 7,
      },
    ),
    (
      "HelenaWayne_fE6O0DJcE",
      {
        id: "HelenaWayne_fE6O0DJcE",
        type_: Player.Type.Person,
        firstName: "Helena",
        lastName: "Wayne",
        rating: 1087,
        matchCount: 7,
      },
    ),
    (
      "Joker_v0z2416fpAZ9o2c",
      {
        id: "Joker_v0z2416fpAZ9o2c",
        type_: Player.Type.Person,
        firstName: "Joker",
        lastName: "",
        rating: 1538,
        matchCount: 1,
      },
    ),
    (
      "HarleyQuinn_-10-02VPH",
      {
        id: "HarleyQuinn_-10-02VPH",
        type_: Player.Type.Person,
        firstName: "Harley",
        lastName: "Quinn",
        rating: 1648,
        matchCount: 1,
      },
    ),
    (
      "VictorFries_cWaQoW014",
      {
        id: "VictorFries_cWaQoW014",
        type_: Player.Type.Person,
        firstName: "Victor",
        lastName: "Fries",
        rating: 862,
        matchCount: 1,
      },
    ),
    (
      "OswaldCobblepot_lfCro",
      {
        id: "OswaldCobblepot_lfCro",
        type_: Player.Type.Person,
        firstName: "Oswald",
        lastName: "Cobblepot",
        rating: 1812,
        matchCount: 1,
      },
    ),
    (
      "RasAlGhul_k9n8k852bHr",
      {
        id: "RasAlGhul_k9n8k852bHr",
        type_: Player.Type.Person,
        firstName: "Ra's",
        lastName: "al Ghul",
        rating: 1404,
        matchCount: 1,
      },
    ),
    (
      "PamelaIsley_vH5vD8uPB",
      {
        id: "PamelaIsley_vH5vD8uPB",
        type_: Player.Type.Person,
        firstName: "Pamela",
        lastName: "Isley",
        rating: 965,
        matchCount: 1,
      },
    ),
    (
      "EdwardNigma_j80JfWOZq",
      {
        id: "EdwardNigma_j80JfWOZq",
        type_: Player.Type.Person,
        firstName: "Edward",
        lastName: "Nigma",
        rating: 948,
        matchCount: 1,
      },
    ),
    (
      "JonathanCrane_R4Q8tVW",
      {
        id: "JonathanCrane_R4Q8tVW",
        type_: Player.Type.Person,
        firstName: "Jonathan",
        lastName: "Crane",
        rating: 899,
        matchCount: 1,
      },
    ),
    (
      "HarveyDent_0eYIiP_Ij5",
      {
        id: "HarveyDent_0eYIiP_Ij5",
        type_: Player.Type.Person,
        firstName: "Harvey",
        lastName: "Dent",
        rating: 1649,
        matchCount: 1,
      },
    ),
    (
      "HugoStrange_az43f9mtS",
      {
        id: "HugoStrange_az43f9mtS",
        type_: Player.Type.Person,
        firstName: "Hugo",
        lastName: "Strange",
        rating: 800,
        matchCount: 0,
      },
    ),
  |]);

let tournaments =
  Map.String.fromArray([|
    (
      "CaouTNel9k70jUJ0h6SYM",
      Tournament.{
        date: Js.Date.fromString("2019-05-22T12:14:47.670Z"),
        id: "CaouTNel9k70jUJ0h6SYM",
        name: "Wayne Manor Open",
        tieBreaks: [|0, 1, 2, 3|],
        byeQueue: [||],
        playerIds: [|
          "BruceWayne_lv_ZsUHTU9",
          "DickGrayson_1C2rCokHH",
          "AlfredPennyworth_y4dW",
          "BarbaraGordon_cL6SpI2",
          "KateKane_klFW6gDfUOTX",
          "SelinaKyle_rJBH-45Xoy",
          "JasonTodd_fc9CeOa-Luw",
          "JamesGordon_1ts9xICT3",
          "HelenaWayne_fE6O0DJcE",
        |],
        roundList: [|
          [|
            {
              id: "FUASEeyES6ez_ROoT6qmU",
              whiteId: "JasonTodd_fc9CeOa-Luw",
              blackId: "DickGrayson_1C2rCokHH",
              result: Match.Result.BlackWon,
              whiteOrigRating: 1238,
              blackOrigRating: 2108,
              whiteNewRating: 1236,
              blackNewRating: 2109,
            },
            {
              id: "gqPyD66QMPF-pup41xsB2",
              whiteId: "JamesGordon_1ts9xICT3",
              blackId: "AlfredPennyworth_y4dW",
              result: Match.Result.BlackWon,
              whiteOrigRating: 1049,
              blackOrigRating: 2260,
              whiteNewRating: 1049,
              blackNewRating: 2260,
            },
            {
              id: "KpS1lQSzsQWQ3VVWJyA2P",
              whiteId: "KateKane_klFW6gDfUOTX",
              blackId: "BarbaraGordon_cL6SpI2",
              result: Match.Result.Draw,
              whiteOrigRating: 1527,
              blackOrigRating: 1755,
              whiteNewRating: 1553,
              blackNewRating: 1722,
            },
            {
              id: "OgFuy-wq8mz378EWat46u",
              whiteId: "SelinaKyle_rJBH-45Xoy",
              blackId: "BruceWayne_lv_ZsUHTU9",
              result: Match.Result.BlackWon,
              whiteOrigRating: 1284,
              blackOrigRating: 1881,
              whiteNewRating: 1278,
              blackNewRating: 1887,
            },
            {
              id: "f8Ps3GUmd0ZRsBBY8rZOp",
              whiteId: "HelenaWayne_fE6O0DJcE",
              blackId: "________DUMMY________",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 831,
              blackOrigRating: 0,
              whiteNewRating: 831,
              blackNewRating: 0,
            },
          |],
          [|
            {
              id: "6seKrw7ehbhL766g6L2PF",
              whiteId: "DickGrayson_1C2rCokHH",
              blackId: "KateKane_klFW6gDfUOTX",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 2109,
              blackOrigRating: 1685,
              whiteNewRating: 2122,
              blackNewRating: 1672,
            },
            {
              id: "TCSjz48ZXqjamtYUFNg0B",
              whiteId: "BruceWayne_lv_ZsUHTU9",
              blackId: "HelenaWayne_fE6O0DJcE",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1887,
              blackOrigRating: 831,
              whiteNewRating: 1887,
              blackNewRating: 830,
            },
            {
              id: "zF64DEsN8sHydpDDsg37E",
              whiteId: "AlfredPennyworth_y4dW",
              blackId: "SelinaKyle_rJBH-45Xoy",
              result: Match.Result.BlackWon,
              whiteOrigRating: 2260,
              blackOrigRating: 1278,
              whiteNewRating: 2101,
              blackNewRating: 1437,
            },
            {
              id: "qVGt1EJq9y0MmvFtumM0A",
              whiteId: "BarbaraGordon_cL6SpI2",
              blackId: "JasonTodd_fc9CeOa-Luw",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1545,
              blackOrigRating: 1236,
              whiteNewRating: 1574,
              blackNewRating: 1207,
            },
            {
              id: "UhfHaRWr_-BtVo22xAuJu",
              whiteId: "JamesGordon_1ts9xICT3",
              blackId: "________DUMMY________",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1049,
              blackOrigRating: 0,
              whiteNewRating: 1049,
              blackNewRating: 0,
            },
          |],
          [|
            {
              id: "odrOOnZJUe0YAwkfUDqUb",
              whiteId: "AlfredPennyworth_y4dW",
              blackId: "BruceWayne_lv_ZsUHTU9",
              result: Match.Result.BlackWon,
              whiteOrigRating: 2101,
              blackOrigRating: 1887,
              whiteNewRating: 1998,
              blackNewRating: 1990,
            },
            {
              id: "qzCMqUwNIDAcFSAuA5yCm",
              whiteId: "HelenaWayne_fE6O0DJcE",
              blackId: "DickGrayson_1C2rCokHH",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 830,
              blackOrigRating: 2122,
              whiteNewRating: 990,
              blackNewRating: 2008,
            },
            {
              id: "6QgVqdtcJPjfVp3UZ8S9g",
              whiteId: "SelinaKyle_rJBH-45Xoy",
              blackId: "BarbaraGordon_cL6SpI2",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1437,
              blackOrigRating: 1574,
              whiteNewRating: 1529,
              blackNewRating: 1464,
            },
            {
              id: "as45gODKMLC5-3_UsTyx5",
              whiteId: "KateKane_klFW6gDfUOTX",
              blackId: "JamesGordon_1ts9xICT3",
              result: Match.Result.BlackWon,
              whiteOrigRating: 1672,
              blackOrigRating: 1049,
              whiteNewRating: 1542,
              blackNewRating: 1244,
            },
            {
              id: "Pc0CWecSfeGNfvBPjyEIj",
              whiteId: "JasonTodd_fc9CeOa-Luw",
              blackId: "________DUMMY________",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1207,
              blackOrigRating: 0,
              whiteNewRating: 1207,
              blackNewRating: 0,
            },
          |],
          [|
            {
              id: "xj0y_Iqkb-g3MDGgmYx2-",
              whiteId: "BruceWayne_lv_ZsUHTU9",
              blackId: "KateKane_klFW6gDfUOTX",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1990,
              blackOrigRating: 1542,
              whiteNewRating: 1998,
              blackNewRating: 1534,
            },
            {
              id: "HWYWtsyaqUkHRExM6kQrt",
              whiteId: "DickGrayson_1C2rCokHH",
              blackId: "JamesGordon_1ts9xICT3",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 2008,
              blackOrigRating: 1244,
              whiteNewRating: 2009,
              blackNewRating: 1243,
            },
            {
              id: "uAzHZVMC71liQZ-6fWWeD",
              whiteId: "HelenaWayne_fE6O0DJcE",
              blackId: "SelinaKyle_rJBH-45Xoy",
              result: Match.Result.BlackWon,
              whiteOrigRating: 990,
              blackOrigRating: 1529,
              whiteNewRating: 983,
              blackNewRating: 1534,
            },
            {
              id: "_tCBn9YNIyto-vXpxm7WI",
              whiteId: "JasonTodd_fc9CeOa-Luw",
              blackId: "AlfredPennyworth_y4dW",
              result: Match.Result.BlackWon,
              whiteOrigRating: 1207,
              blackOrigRating: 1998,
              whiteNewRating: 1205,
              blackNewRating: 1999,
            },
            {
              id: "L7yatE2oVKlV7LOY6-d7Y",
              whiteId: "BarbaraGordon_cL6SpI2",
              blackId: "________DUMMY________",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1464,
              blackOrigRating: 0,
              whiteNewRating: 1464,
              blackNewRating: 0,
            },
          |],
        |],
      },
    ),
    (
      "tvAdS4YbSOznrBgrg0ITA",
      {
        date: Js.Date.fromString("2019-05-29T12:15:20.593Z"),
        id: "tvAdS4YbSOznrBgrg0ITA",
        name: "The Battle for Gotham City",
        tieBreaks: [|0, 1, 2, 3|],
        byeQueue: [||],
        playerIds: [|
          "BruceWayne_lv_ZsUHTU9",
          "DickGrayson_1C2rCokHH",
          "AlfredPennyworth_y4dW",
          "BarbaraGordon_cL6SpI2",
          "KateKane_klFW6gDfUOTX",
          "SelinaKyle_rJBH-45Xoy",
          "JasonTodd_fc9CeOa-Luw",
          "JamesGordon_1ts9xICT3",
          "HelenaWayne_fE6O0DJcE",
          "Joker_v0z2416fpAZ9o2c",
          "HarleyQuinn_-10-02VPH",
          "VictorFries_cWaQoW014",
          "OswaldCobblepot_lfCro",
          "RasAlGhul_k9n8k852bHr",
          "PamelaIsley_vH5vD8uPB",
          "EdwardNigma_j80JfWOZq",
          "JonathanCrane_R4Q8tVW",
          "HarveyDent_0eYIiP_Ij5",
        |],
        roundList: [|
          [|
            {
              id: "5f8GYcR8V44NYvTN1cZle",
              whiteId: "EdwardNigma_j80JfWOZq",
              blackId: "BruceWayne_lv_ZsUHTU9",
              result: Match.Result.BlackWon,
              whiteOrigRating: 950,
              blackOrigRating: 1998,
              whiteNewRating: 948,
              blackNewRating: 1998,
            },
            {
              id: "GPTct4sL368SryTLFUu8E",
              whiteId: "JonathanCrane_R4Q8tVW",
              blackId: "AlfredPennyworth_y4dW",
              result: Match.Result.BlackWon,
              whiteOrigRating: 900,
              blackOrigRating: 1999,
              whiteNewRating: 899,
              blackNewRating: 1999,
            },
            {
              id: "AxtoztZ6O19nyrLfZ4YaU",
              whiteId: "HarveyDent_0eYIiP_Ij5",
              blackId: "DickGrayson_1C2rCokHH",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 850,
              blackOrigRating: 2009,
              whiteNewRating: 1649,
              blackNewRating: 1909,
            },
            {
              id: "bUM_tWQsAtPe1gqRzlXd1",
              whiteId: "RasAlGhul_k9n8k852bHr",
              blackId: "SelinaKyle_rJBH-45Xoy",
              result: Match.Result.Draw,
              whiteOrigRating: 1050,
              blackOrigRating: 1534,
              whiteNewRating: 1404,
              blackNewRating: 1495,
            },
            {
              id: "bAOVlP-M5xaPk1qofNReb",
              whiteId: "OswaldCobblepot_lfCro",
              blackId: "BarbaraGordon_cL6SpI2",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1100,
              blackOrigRating: 1464,
              whiteNewRating: 1812,
              blackNewRating: 1345,
            },
            {
              id: "4omlgiGSaE1BmrHdABSym",
              whiteId: "PamelaIsley_vH5vD8uPB",
              blackId: "KateKane_klFW6gDfUOTX",
              result: Match.Result.BlackWon,
              whiteOrigRating: 1000,
              blackOrigRating: 1534,
              whiteNewRating: 965,
              blackNewRating: 1539,
            },
            {
              id: "ysdEVYS2AyuKyOAwLLpTF",
              whiteId: "HarleyQuinn_-10-02VPH",
              blackId: "JamesGordon_1ts9xICT3",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1200,
              blackOrigRating: 1242,
              whiteNewRating: 1648,
              blackNewRating: 1167,
            },
            {
              id: "YoJ9WGokAYrmJjfxCCf87",
              whiteId: "VictorFries_cWaQoW014",
              blackId: "Joker_v0z2416fpAZ9o2c",
              result: Match.Result.BlackWon,
              whiteOrigRating: 1150,
              blackOrigRating: 1250,
              whiteNewRating: 862,
              blackNewRating: 1538,
            },
            {
              id: "Az7SBl3cs7rbwKPBI0IsU",
              whiteId: "HelenaWayne_fE6O0DJcE",
              blackId: "JasonTodd_fc9CeOa-Luw",
              result: Match.Result.WhiteWon,
              whiteOrigRating: 983,
              blackOrigRating: 1205,
              whiteNewRating: 1087,
              blackNewRating: 1101,
            },
          |],
          [||],
        |],
      },
    ),
  |]);