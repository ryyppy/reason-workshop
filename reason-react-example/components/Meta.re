module Helmet = ReactHelmet.Helmet;

open Util;
let component = ReasonReact.statelessComponent("Meta");

/* [@bs.module] external icon16: string = "../assets/favicon/favicon-16.png";
   [@bs.module] external icon32: string = "../assets/favicon/favicon-32.png";
   [@bs.module] external icon57: string = "../assets/favicon/favicon-57.png";
   [@bs.module] external icon60: string = "../assets/favicon/favicon-60.png";
   [@bs.module] external icon64: string = "../assets/favicon/favicon-64.png";
   [@bs.module] external icon70: string = "../assets/favicon/favicon-70.png";
   [@bs.module] external icon72: string = "../assets/favicon/favicon-72.png";
   [@bs.module] external icon76: string = "../assets/favicon/favicon-76.png";
   [@bs.module] external icon96: string = "../assets/favicon/favicon-96.png";
   [@bs.module] external icon114: string = "../assets/favicon/favicon-114.png";
   [@bs.module] external icon120: string = "../assets/favicon/favicon-120.png";
   [@bs.module] external icon144: string = "../assets/favicon/favicon-144.png";
   [@bs.module] external icon150: string = "../assets/favicon/favicon-150.png";
   [@bs.module] external icon152: string = "../assets/favicon/favicon-152.png";
   [@bs.module] external icon160: string = "../assets/favicon/favicon-160.png";
   [@bs.module] external icon180: string = "../assets/favicon/favicon-180.png";
   [@bs.module] external icon192: string = "../assets/favicon/favicon-192.png";
   [@bs.module] external icon310: string = "../assets/favicon/favicon-310.png";
   [@bs.module] external icon: string = "../assets/favicon/favicon.ico";
   [@bs.module] external browserconfig: string = "../assets/favicon/browserconfig.xml"; */

let make =
    (
      ~siteName: string,
      ~title: string,
      ~description: string,
      ~keywords: array(string),
      _children,
    ) => {
  ...component,
  render: _self =>
    <Helmet>
      <link rel="canonical" href="https://diemagischezehn.at/" />
      <title> {s(siteName ++ " - " ++ title)} </title>
      <meta charSet="UTF-8" />
      <meta
        name="viewport"
        content="width=device-width, initial-scale=1, maximum-scale=1, minimal-ui"
      />
      <meta name="description" content=description />
      <meta name="keywords" content={Util.join(~sep=",", keywords)} />
    </Helmet>,
  /* <link rel="shortcut icon" href=icon /> */
  /* <link rel="icon" sizes="16x16 32x32 64x64" href=icon />
     <link
       rel="icon"
       type_="image/png"
       sizes="196x196"
       href=icon192
     />
     <link
       rel="icon"
       type_="image/png"
       sizes="160x160"
       href=icon160
     />
     <link
       rel="icon"
       type_="image/png"
       sizes="96x96"
       href=icon96
     />
     <link
       rel="icon"
       type_="image/png"
       sizes="64x64"
       href=icon64
     />
     <link
       rel="icon"
       type_="image/png"
       sizes="32x32"
       href=icon32
     />
     <link
       rel="icon"
       type_="image/png"
       sizes="16x16"
       href=icon16
     />
     <link rel="apple-touch-icon" href=icon57 />
     <link rel="apple-touch-icon" sizes="114x114" href=icon114 />
     <link rel="apple-touch-icon" sizes="72x72" href=icon72 />
     <link rel="apple-touch-icon" sizes="144x144" href=icon144 />
     <link rel="apple-touch-icon" sizes="60x60" href=icon60 />
     <link rel="apple-touch-icon" sizes="120x120" href=icon120 />
     <link rel="apple-touch-icon" sizes="76x76" href=icon76 />
     <link rel="apple-touch-icon" sizes="152x152" href=icon152 />
     <link rel="apple-touch-icon" sizes="180x180" href=icon180 />
     <meta name="msapplication-TileColor" content="#FFFFFF" />
     <meta name="msapplication-TileImage" content=icon144 />
     <meta name="msapplication-config" content=browserconfig /> */
  /* <meta name="twitter:image" content="./meta-image.png" /> */
};