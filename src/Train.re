class type _chain =
  [@bs]
  {
    pub walk: unit => array(string)
  };

type chain = Js.t(_chain);

[@bs.new] [@bs.module "markov-chains"] external getChain : (array(array(string)), int) => chain = "default";

let rec tokenizeRow = (acc, row) =>
  switch (row) {
    | [] => acc
    | [hd, ...tl] =>
      switch (acc) {
        | "" => tokenizeRow(string_of_int(hd), tl)
        | _ => tokenizeRow(acc ++ "-" ++ string_of_int(hd), tl)
        };
    };

let rec tokenizeMatrix = (acc, matrix) =>
  switch (matrix) {
    | [] => Array.of_list(List.rev(acc))
    | [hd, ...tl] =>
      tokenizeMatrix(
        [hd |> Array.to_list |> tokenizeRow(""), ...acc],
        tl
      );
    };

let rec tokenize = (acc, matrices) =>
  switch (matrices) {
    | [] => Array.of_list(List.rev(acc))
    | [hd, ...tl] => 
      tokenize(
        [hd |> Array.to_list |> tokenizeMatrix([]), ...acc],
        tl
      );
    };

let rec chainToMatrix = (acc, chain, i) =>
  switch (i > 7) {
    | true => acc
    | false =>
      switch (chain) {
        | [] => acc
        | [hd, ...tl] =>
          acc[i] = Array.map(int_of_string, Js.String.split("-", hd));
          chainToMatrix(acc, tl, i+1);
        }
    };

let rec getLongResult = states => {
  let chain = getChain(states, 4)##walk();
  switch (Array.length(chain) > 3) {
    | true =>
      chainToMatrix(Array.make_matrix(8, 7, 0), Array.to_list(chain), 0);
    | false =>
      getLongResult(states);
    };
}

let train = (matrix) => {
  let state = tokenize([], matrix);
  let states = Array.concat([state, state, state, state]);
  let learnedMatrix = Array.make(4, Array.make_matrix(8, 7, 0))
  learnedMatrix[0] = getLongResult(states);
  learnedMatrix[1] = getLongResult(states);
  learnedMatrix[2] = getLongResult(states);
  learnedMatrix[3] = getLongResult(states);

  learnedMatrix;
};
