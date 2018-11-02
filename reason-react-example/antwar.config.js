const path = require("path");
const page = require("./utils/page");

module.exports = {
  apiUrl: "",
  template: {
    file: path.resolve(__dirname, "templates/page.ejs"),
    context: {
      helmet: {}
    }
  },
  renderPage: require("./utils/render-page"),
  output: "build",
  layout: () => require("./layouts").default,
  paths: {
    // "404.html": page("404", {
    //   description: "Page was not found",
    //   title: "Page not found",
    // }),
    "/": page("index.mdx", { title: "Home" }),
    "help": page("help.mdx", { title: "Help" }),
    "exercise1": page("exercise1.mdx", { title: "Exercise1" }),
    "exercise2": page("exercise2.mdx", { title: "Exercise2" }),
  }
};