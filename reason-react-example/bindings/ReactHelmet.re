module Helmet = {
  [@bs.module "react-helmet"]
  external helmetClass: ReasonReact.reactClass = "Helmet";
  type metaT =
    option(
      array({
        .
        "name": string,
        "content": string,
      }),
    );

  let make =
      (~title: option(string)=?, ~bodyAttributes=?, ~meta: metaT=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=helmetClass,
      ~props={
        "title": Js.Nullable.fromOption(title),
        "bodyAttributes": Js.Nullable.fromOption(bodyAttributes),
        "meta": Js.Nullable.fromOption(meta),
      },
      children,
    );
};