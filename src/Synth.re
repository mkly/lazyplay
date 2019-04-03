type voice;
type frequency;

class type _synth =
  [@bs]
  {
    pub toMaster: unit => unit;
    pub triggerAttackRelease: (array(frequency), float) => unit
  };

type synth = Js.t(_synth);

[@bs.module "tone"] [@bs.val] external voice : voice = "Synth";
[@bs.new] [@bs.module "tone"] external createSynth : (int, voice) => synth = "PolySynth";
[@bs.module "tone"] external frequency : string => frequency = "Frequency";


let synth = createSynth(8, voice);
synth##toMaster();

let rec processRow = (c, acc, row) => {
  switch (row) {
    | [] => acc
    | [hd, ...tl] =>
      switch (hd == 1) {
        | false => processRow(c+1, acc, tl)
        | true =>
          switch (c) {
            | 1 => processRow(c+1, [frequency("A3"), ...acc], tl)
            | 0 => processRow(c+1, [frequency("B3"), ...acc], tl)
            | 6 => processRow(c+1, [frequency("C3"), ...acc], tl)
            | 5 => processRow(c+1, [frequency("D3"), ...acc], tl)
            | 4 => processRow(c+1, [frequency("E3"), ...acc], tl)
            | 3 => processRow(c+1, [frequency("F3"), ...acc], tl)
            | 2 => processRow(c+1, [frequency("G3"), ...acc], tl)
            | _ => processRow(c+1, acc, tl)
            }
        }
    };
};

let playNote = (row, duration) => {
  let frequencies = row
    |> Array.to_list
    |> processRow(0, [])
    |> Array.of_list;

  synth##triggerAttackRelease(frequencies, duration);
};
