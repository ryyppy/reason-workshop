const React = require("react");
const ReactDOMServer = require("react-dom/server");
const {Helmet} = require("react-helmet");

const { Route, StaticRouter } = require("react-router");

module.exports = function renderDefault({ location, content: component }, cb) {
  const helmetContext = {
    helmet: {}
  };
  const page = React.createElement(
    StaticRouter,
    { location, context: { helmetContext } },
    React.createElement(Route, { component })
  );
  // <StaticRouter location context>
  //   <Route component />
  // </StaticRouter>

  const html = ReactDOMServer.renderToStaticMarkup(page);
  const helmet = Helmet.renderStatic();

  cb(null, {
    html,
    context: { helmet }
  });
};
