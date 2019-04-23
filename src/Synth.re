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

let getNote = (note, octave: string) =>
  String.concat("", [note,octave]) |> frequency

let rec processRow = (c, acc, octave, row) => {
  switch (row) {
    | [] => acc
    | [hd, ...tl] =>
      switch (hd == 1) {
        | false => processRow(c+1, acc, octave, tl)
        | true =>
          switch (c) {
            | 1 => processRow(c+1, [getNote("A", octave), ...acc], octave, tl)
            | 0 => processRow(c+1, [getNote("B", octave), ...acc], octave, tl)
            | 6 => processRow(c+1, [getNote("C", octave), ...acc], octave, tl)
            | 5 => processRow(c+1, [getNote("D", octave), ...acc], octave, tl)
            | 4 => processRow(c+1, [getNote("E", octave), ...acc], octave, tl)
            | 3 => processRow(c+1, [getNote("F", octave), ...acc], octave, tl)
            | 2 => processRow(c+1, [getNote("G", octave), ...acc], octave, tl)
            | _ => processRow(c+1, acc, octave, tl)
            }
        }
    };
};

let playNote = (row, duration, octave) => {
  let frequencies = row
    |> Array.to_list
    |> processRow(0, [], octave)
    |> Array.of_list;

  synth##triggerAttackRelease(frequencies, duration);
};
