/* Test data */
let name = "Goethe";
let msg = "Jetzt sitz ich hier ich armer Tor, und bin so klug wie je zuvor";

/* TASK 1 */
/* Without any labels */
let citation = (name: string, msg: string, loud: bool) => {
  /* Tertinary operator in Reason */
  let maybeLoudMsg = loud ? String.uppercase(msg) : msg;
  {j|"$maybeLoudMsg" - $name|j};
};

/* TASK 2 */
/* With labelled arguments - Last unit parameter is useful to prevent unintentional currying and */
/* is not needed by default */
let citation2 = (~name: string, ~msg: string, ~loud: bool, ()) =>
  citation(name, msg, loud);

/* Variation of applying bindings as parameters */
citation2(~name, ~msg, ~loud=false, ()) |> Js.log;
citation2(~name, ~msg, ~loud=true, ()) |> Js.log;

/* Partially apply Goethe as name and only cite quietly */
let goetheCite = citation2(~name, ~loud=false);
goetheCite(~msg="Rock me, Amadeus", ()) |> Js.log;

/* TASK 3 */
/* Make loud parameter optional (default to false) - Last unit () is needed here */
let citation3 = (~name: string, ~msg: string, ~loud: option(bool)=?, ()) =>
  citation(name, msg, Belt.Option.getWithDefault(loud, false));

citation3(~msg="Who you gonna call?", ~name="Ghostbusters", ~loud=true, ())
|> Js.log;

/* TASK 4 */
/* To get rid of the unit () parameter, we will use the msg */
/* parameter as unlabeled argument instead */
/* Note how we passed the optional argument ~loud to the citation3 function! */
let citation4 = (~name: string, ~loud: option(bool)=?, msg: string) =>
  citation3(~name, ~msg, ~loud?, ());

let farinUrlaubCite = citation4(~name="Farin Urlaub");

/* Nicer to use, since msg is now unlabeled (also we don't need any unit () anymore) */
farinUrlaubCite("Ja ich schlafe in der Dusche...") |> Js.log;