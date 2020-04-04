open Belt;
open Data;
let id = Data.Id.fromString;

let config =
  Config.{
    byeValue: ByeValue.Full,
    avoidPairs:
      [|
        ("BarbaraGordon_cL6SpI2", "JamesGordon_1ts9xICT3"),
        ("Joker_v0z2416fpAZ9o2c", "HarleyQuinn_-10-02VPH"),
        ("HelenaWayne_fE6O0DJcE", "BruceWayne_lv_ZsUHTU9"),
      |]
      ->Array.keepMap(((a, b)) => Pair.make(id(a), id(b)))
      ->Pair.Set.fromArray,
    lastBackup: Js.Date.fromString("1970-01-01T00:00:00.000Z"),
  };

let players: array((string, Player.t)) = [|
  (
    "BruceWayne_lv_ZsUHTU9",
    Player.{
      id: "BruceWayne_lv_ZsUHTU9"->id,
      type_: Player.Type.Person,
      firstName: "Bruce",
      lastName: "Wayne",
      rating: 1998,
      matchCount: 9,
    },
  ),
  (
    "DickGrayson_1C2rCokHH",
    Player.{
      id: "DickGrayson_1C2rCokHH"->id,
      type_: Player.Type.Person,
      firstName: "Dick",
      lastName: "Grayson",
      rating: 1909,
      matchCount: 9,
    },
  ),
  (
    "AlfredPennyworth_y4dW",
    Player.{
      id: "AlfredPennyworth_y4dW"->id,
      type_: Player.Type.Person,
      firstName: "Alfred",
      lastName: "Pennyworth",
      rating: 1999,
      matchCount: 9,
    },
  ),
  (
    "BarbaraGordon_cL6SpI2",
    Player.{
      id: "BarbaraGordon_cL6SpI2"->id,
      type_: Player.Type.Person,
      firstName: "Barbara",
      lastName: "Gordon",
      rating: 1345,
      matchCount: 7,
    },
  ),
  (
    "KateKane_klFW6gDfUOTX",
    Player.{
      id: "KateKane_klFW6gDfUOTX"->id,
      type_: Player.Type.Person,
      firstName: "Kate",
      lastName: "Kane",
      rating: 1539,
      matchCount: 9,
    },
  ),
  (
    "SelinaKyle_rJBH-45Xoy",
    Player.{
      id: "SelinaKyle_rJBH-45Xoy"->id,
      type_: Player.Type.Person,
      firstName: "Selina",
      lastName: "Kyle",
      rating: 1495,
      matchCount: 9,
    },
  ),
  (
    "JasonTodd_fc9CeOa-Luw",
    Player.{
      id: "JasonTodd_fc9CeOa-Luw"->id,
      type_: Player.Type.Person,
      firstName: "Jason",
      lastName: "Todd",
      rating: 1101,
      matchCount: 7,
    },
  ),
  (
    "JamesGordon_1ts9xICT3",
    Player.{
      id: "JamesGordon_1ts9xICT3"->id,
      type_: Player.Type.Person,
      firstName: "James",
      lastName: "Gordon",
      rating: 1167,
      matchCount: 7,
    },
  ),
  (
    "HelenaWayne_fE6O0DJcE",
    Player.{
      id: "HelenaWayne_fE6O0DJcE"->id,
      type_: Player.Type.Person,
      firstName: "Helena",
      lastName: "Wayne",
      rating: 1087,
      matchCount: 7,
    },
  ),
  (
    "Joker_v0z2416fpAZ9o2c",
    Player.{
      id: "Joker_v0z2416fpAZ9o2c"->id,
      type_: Player.Type.Person,
      firstName: "Joker",
      lastName: "",
      rating: 1538,
      matchCount: 1,
    },
  ),
  (
    "HarleyQuinn_-10-02VPH",
    Player.{
      id: "HarleyQuinn_-10-02VPH"->id,
      type_: Player.Type.Person,
      firstName: "Harley",
      lastName: "Quinn",
      rating: 1648,
      matchCount: 1,
    },
  ),
  (
    "VictorFries_cWaQoW014",
    Player.{
      id: "VictorFries_cWaQoW014"->id,
      type_: Player.Type.Person,
      firstName: "Victor",
      lastName: "Fries",
      rating: 862,
      matchCount: 1,
    },
  ),
  (
    "OswaldCobblepot_lfCro",
    Player.{
      id: "OswaldCobblepot_lfCro"->id,
      type_: Player.Type.Person,
      firstName: "Oswald",
      lastName: "Cobblepot",
      rating: 1812,
      matchCount: 1,
    },
  ),
  (
    "RasAlGhul_k9n8k852bHr",
    Player.{
      id: "RasAlGhul_k9n8k852bHr"->id,
      type_: Player.Type.Person,
      firstName: "Ra's",
      lastName: "al Ghul",
      rating: 1404,
      matchCount: 1,
    },
  ),
  (
    "PamelaIsley_vH5vD8uPB",
    Player.{
      id: "PamelaIsley_vH5vD8uPB"->id,
      type_: Player.Type.Person,
      firstName: "Pamela",
      lastName: "Isley",
      rating: 965,
      matchCount: 1,
    },
  ),
  (
    "EdwardNigma_j80JfWOZq",
    Player.{
      id: "EdwardNigma_j80JfWOZq"->id,
      type_: Player.Type.Person,
      firstName: "Edward",
      lastName: "Nigma",
      rating: 948,
      matchCount: 1,
    },
  ),
  (
    "JonathanCrane_R4Q8tVW",
    Player.{
      id: "JonathanCrane_R4Q8tVW"->id,
      type_: Player.Type.Person,
      firstName: "Jonathan",
      lastName: "Crane",
      rating: 899,
      matchCount: 1,
    },
  ),
  (
    "HarveyDent_0eYIiP_Ij5",
    Player.{
      id: "HarveyDent_0eYIiP_Ij5"->id,
      type_: Player.Type.Person,
      firstName: "Harvey",
      lastName: "Dent",
      rating: 1649,
      matchCount: 1,
    },
  ),
  (
    "HugoStrange_az43f9mtS",
    Player.{
      id: "HugoStrange_az43f9mtS"->id,
      type_: Player.Type.Person,
      firstName: "Hugo",
      lastName: "Strange",
      rating: 800,
      matchCount: 0,
    },
  ),
|];

let tournaments: array((string, Tournament.t)) = [|
  (
    "CaouTNel9k70jUJ0h6SYM",
    Tournament.{
      date: Js.Date.fromString("2019-05-22T12:14:47.670Z"),
      id: "CaouTNel9k70jUJ0h6SYM"->id,
      name: "Wayne Manor Open",
      tieBreaks:
        Scoring.TieBreak.(
          [|Median, Solkoff, Cumulative, CumulativeOfOpposition|]
        ),
      byeQueue: [||],
      playerIds: [
        "BruceWayne_lv_ZsUHTU9"->id,
        "DickGrayson_1C2rCokHH"->id,
        "AlfredPennyworth_y4dW"->id,
        "BarbaraGordon_cL6SpI2"->id,
        "KateKane_klFW6gDfUOTX"->id,
        "SelinaKyle_rJBH-45Xoy"->id,
        "JasonTodd_fc9CeOa-Luw"->id,
        "JamesGordon_1ts9xICT3"->id,
        "HelenaWayne_fE6O0DJcE"->id,
      ],
      roundList:
        [|
          [|
            {
              Match.id: "FUASEeyES6ez_ROoT6qmU"->id,
              whiteId: "JasonTodd_fc9CeOa-Luw"->id,
              blackId: "DickGrayson_1C2rCokHH"->id,
              result: Match.Result.BlackWon,
              whiteOrigRating: 1238,
              blackOrigRating: 2108,
              whiteNewRating: 1236,
              blackNewRating: 2109,
            },
            {
              Match.id: "gqPyD66QMPF-pup41xsB2"->id,
              whiteId: "JamesGordon_1ts9xICT3"->id,
              blackId: "AlfredPennyworth_y4dW"->id,
              result: Match.Result.BlackWon,
              whiteOrigRating: 1049,
              blackOrigRating: 2260,
              whiteNewRating: 1049,
              blackNewRating: 2260,
            },
            {
              Match.id: "KpS1lQSzsQWQ3VVWJyA2P"->id,
              whiteId: "KateKane_klFW6gDfUOTX"->id,
              blackId: "BarbaraGordon_cL6SpI2"->id,
              result: Match.Result.Draw,
              whiteOrigRating: 1527,
              blackOrigRating: 1755,
              whiteNewRating: 1553,
              blackNewRating: 1722,
            },
            {
              Match.id: "OgFuy-wq8mz378EWat46u"->id,
              whiteId: "SelinaKyle_rJBH-45Xoy"->id,
              blackId: "BruceWayne_lv_ZsUHTU9"->id,
              result: Match.Result.BlackWon,
              whiteOrigRating: 1284,
              blackOrigRating: 1881,
              whiteNewRating: 1278,
              blackNewRating: 1887,
            },
            {
              Match.id: "f8Ps3GUmd0ZRsBBY8rZOp"->id,
              whiteId: "HelenaWayne_fE6O0DJcE"->id,
              blackId: "________DUMMY________"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 831,
              blackOrigRating: 0,
              whiteNewRating: 831,
              blackNewRating: 0,
            },
          |]
          ->Rounds.Round.fromArray,
          [|
            {
              Match.id: "6seKrw7ehbhL766g6L2PF"->id,
              whiteId: "DickGrayson_1C2rCokHH"->id,
              blackId: "KateKane_klFW6gDfUOTX"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 2109,
              blackOrigRating: 1685,
              whiteNewRating: 2122,
              blackNewRating: 1672,
            },
            {
              Match.id: "TCSjz48ZXqjamtYUFNg0B"->id,
              whiteId: "BruceWayne_lv_ZsUHTU9"->id,
              blackId: "HelenaWayne_fE6O0DJcE"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1887,
              blackOrigRating: 831,
              whiteNewRating: 1887,
              blackNewRating: 830,
            },
            {
              Match.id: "zF64DEsN8sHydpDDsg37E"->id,
              whiteId: "AlfredPennyworth_y4dW"->id,
              blackId: "SelinaKyle_rJBH-45Xoy"->id,
              result: Match.Result.BlackWon,
              whiteOrigRating: 2260,
              blackOrigRating: 1278,
              whiteNewRating: 2101,
              blackNewRating: 1437,
            },
            {
              Match.id: "qVGt1EJq9y0MmvFtumM0A"->id,
              whiteId: "BarbaraGordon_cL6SpI2"->id,
              blackId: "JasonTodd_fc9CeOa-Luw"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1545,
              blackOrigRating: 1236,
              whiteNewRating: 1574,
              blackNewRating: 1207,
            },
            {
              Match.id: "UhfHaRWr_-BtVo22xAuJu"->id,
              whiteId: "JamesGordon_1ts9xICT3"->id,
              blackId: "________DUMMY________"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1049,
              blackOrigRating: 0,
              whiteNewRating: 1049,
              blackNewRating: 0,
            },
          |]
          ->Rounds.Round.fromArray,
          [|
            {
              Match.id: "odrOOnZJUe0YAwkfUDqUb"->id,
              whiteId: "AlfredPennyworth_y4dW"->id,
              blackId: "BruceWayne_lv_ZsUHTU9"->id,
              result: Match.Result.BlackWon,
              whiteOrigRating: 2101,
              blackOrigRating: 1887,
              whiteNewRating: 1998,
              blackNewRating: 1990,
            },
            {
              Match.id: "qzCMqUwNIDAcFSAuA5yCm"->id,
              whiteId: "HelenaWayne_fE6O0DJcE"->id,
              blackId: "DickGrayson_1C2rCokHH"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 830,
              blackOrigRating: 2122,
              whiteNewRating: 990,
              blackNewRating: 2008,
            },
            {
              Match.id: "6QgVqdtcJPjfVp3UZ8S9g"->id,
              whiteId: "SelinaKyle_rJBH-45Xoy"->id,
              blackId: "BarbaraGordon_cL6SpI2"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1437,
              blackOrigRating: 1574,
              whiteNewRating: 1529,
              blackNewRating: 1464,
            },
            {
              Match.id: "as45gODKMLC5-3_UsTyx5"->id,
              whiteId: "KateKane_klFW6gDfUOTX"->id,
              blackId: "JamesGordon_1ts9xICT3"->id,
              result: Match.Result.BlackWon,
              whiteOrigRating: 1672,
              blackOrigRating: 1049,
              whiteNewRating: 1542,
              blackNewRating: 1244,
            },
            {
              Match.id: "Pc0CWecSfeGNfvBPjyEIj"->id,
              whiteId: "JasonTodd_fc9CeOa-Luw"->id,
              blackId: "________DUMMY________"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1207,
              blackOrigRating: 0,
              whiteNewRating: 1207,
              blackNewRating: 0,
            },
          |]
          ->Rounds.Round.fromArray,
          [|
            {
              Match.id: "xj0y_Iqkb-g3MDGgmYx2-"->id,
              whiteId: "BruceWayne_lv_ZsUHTU9"->id,
              blackId: "KateKane_klFW6gDfUOTX"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1990,
              blackOrigRating: 1542,
              whiteNewRating: 1998,
              blackNewRating: 1534,
            },
            {
              Match.id: "HWYWtsyaqUkHRExM6kQrt"->id,
              whiteId: "DickGrayson_1C2rCokHH"->id,
              blackId: "JamesGordon_1ts9xICT3"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 2008,
              blackOrigRating: 1244,
              whiteNewRating: 2009,
              blackNewRating: 1243,
            },
            {
              Match.id: "uAzHZVMC71liQZ-6fWWeD"->id,
              whiteId: "HelenaWayne_fE6O0DJcE"->id,
              blackId: "SelinaKyle_rJBH-45Xoy"->id,
              result: Match.Result.BlackWon,
              whiteOrigRating: 990,
              blackOrigRating: 1529,
              whiteNewRating: 983,
              blackNewRating: 1534,
            },
            {
              Match.id: "_tCBn9YNIyto-vXpxm7WI"->id,
              whiteId: "JasonTodd_fc9CeOa-Luw"->id,
              blackId: "AlfredPennyworth_y4dW"->id,
              result: Match.Result.BlackWon,
              whiteOrigRating: 1207,
              blackOrigRating: 1998,
              whiteNewRating: 1205,
              blackNewRating: 1999,
            },
            {
              Match.id: "L7yatE2oVKlV7LOY6-d7Y"->id,
              whiteId: "BarbaraGordon_cL6SpI2"->id,
              blackId: "________DUMMY________"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1464,
              blackOrigRating: 0,
              whiteNewRating: 1464,
              blackNewRating: 0,
            },
          |]
          ->Rounds.Round.fromArray,
        |]
        ->Rounds.fromArray,
    },
  ),
  (
    "tvAdS4YbSOznrBgrg0ITA",
    Tournament.{
      date: Js.Date.fromString("2019-05-29T12:15:20.593Z"),
      id: "tvAdS4YbSOznrBgrg0ITA"->id,
      name: "The Battle for Gotham City",
      tieBreaks:
        Scoring.TieBreak.(
          [|Median, Solkoff, Cumulative, CumulativeOfOpposition|]
        ),
      byeQueue: [||],
      playerIds: [
        "BruceWayne_lv_ZsUHTU9"->id,
        "DickGrayson_1C2rCokHH"->id,
        "AlfredPennyworth_y4dW"->id,
        "BarbaraGordon_cL6SpI2"->id,
        "KateKane_klFW6gDfUOTX"->id,
        "SelinaKyle_rJBH-45Xoy"->id,
        "JasonTodd_fc9CeOa-Luw"->id,
        "JamesGordon_1ts9xICT3"->id,
        "HelenaWayne_fE6O0DJcE"->id,
        "Joker_v0z2416fpAZ9o2c"->id,
        "HarleyQuinn_-10-02VPH"->id,
        "VictorFries_cWaQoW014"->id,
        "OswaldCobblepot_lfCro"->id,
        "RasAlGhul_k9n8k852bHr"->id,
        "PamelaIsley_vH5vD8uPB"->id,
        "EdwardNigma_j80JfWOZq"->id,
        "JonathanCrane_R4Q8tVW"->id,
        "HarveyDent_0eYIiP_Ij5"->id,
      ],
      roundList:
        [|
          [|
            {
              Match.id: "5f8GYcR8V44NYvTN1cZle"->id,
              whiteId: "EdwardNigma_j80JfWOZq"->id,
              blackId: "BruceWayne_lv_ZsUHTU9"->id,
              result: Match.Result.BlackWon,
              whiteOrigRating: 950,
              blackOrigRating: 1998,
              whiteNewRating: 948,
              blackNewRating: 1998,
            },
            {
              Match.id: "GPTct4sL368SryTLFUu8E"->id,
              whiteId: "JonathanCrane_R4Q8tVW"->id,
              blackId: "AlfredPennyworth_y4dW"->id,
              result: Match.Result.BlackWon,
              whiteOrigRating: 900,
              blackOrigRating: 1999,
              whiteNewRating: 899,
              blackNewRating: 1999,
            },
            {
              Match.id: "AxtoztZ6O19nyrLfZ4YaU"->id,
              whiteId: "HarveyDent_0eYIiP_Ij5"->id,
              blackId: "DickGrayson_1C2rCokHH"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 850,
              blackOrigRating: 2009,
              whiteNewRating: 1649,
              blackNewRating: 1909,
            },
            {
              Match.id: "bUM_tWQsAtPe1gqRzlXd1"->id,
              whiteId: "RasAlGhul_k9n8k852bHr"->id,
              blackId: "SelinaKyle_rJBH-45Xoy"->id,
              result: Match.Result.Draw,
              whiteOrigRating: 1050,
              blackOrigRating: 1534,
              whiteNewRating: 1404,
              blackNewRating: 1495,
            },
            {
              Match.id: "bAOVlP-M5xaPk1qofNReb"->id,
              whiteId: "OswaldCobblepot_lfCro"->id,
              blackId: "BarbaraGordon_cL6SpI2"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1100,
              blackOrigRating: 1464,
              whiteNewRating: 1812,
              blackNewRating: 1345,
            },
            {
              Match.id: "4omlgiGSaE1BmrHdABSym"->id,
              whiteId: "PamelaIsley_vH5vD8uPB"->id,
              blackId: "KateKane_klFW6gDfUOTX"->id,
              result: Match.Result.BlackWon,
              whiteOrigRating: 1000,
              blackOrigRating: 1534,
              whiteNewRating: 965,
              blackNewRating: 1539,
            },
            {
              Match.id: "ysdEVYS2AyuKyOAwLLpTF"->id,
              whiteId: "HarleyQuinn_-10-02VPH"->id,
              blackId: "JamesGordon_1ts9xICT3"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 1200,
              blackOrigRating: 1242,
              whiteNewRating: 1648,
              blackNewRating: 1167,
            },
            {
              Match.id: "YoJ9WGokAYrmJjfxCCf87"->id,
              whiteId: "VictorFries_cWaQoW014"->id,
              blackId: "Joker_v0z2416fpAZ9o2c"->id,
              result: Match.Result.BlackWon,
              whiteOrigRating: 1150,
              blackOrigRating: 1250,
              whiteNewRating: 862,
              blackNewRating: 1538,
            },
            {
              Match.id: "Az7SBl3cs7rbwKPBI0IsU"->id,
              whiteId: "HelenaWayne_fE6O0DJcE"->id,
              blackId: "JasonTodd_fc9CeOa-Luw"->id,
              result: Match.Result.WhiteWon,
              whiteOrigRating: 983,
              blackOrigRating: 1205,
              whiteNewRating: 1087,
              blackNewRating: 1101,
            },
          |]
          ->Rounds.Round.fromArray,
          Rounds.Round.empty,
        |]
        ->Rounds.fromArray,
    },
  ),
|];
