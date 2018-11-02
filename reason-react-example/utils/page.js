module.exports = function page(
  filepath,
  meta = {}
) {
  const name = filepath.split(".")[0];
  const ret = () => {
    const component = require(`../pages/${filepath}`).default;

    component.description = meta.description || "";
    component.title = meta.title || "";
    component.keywords = meta.keywords || [];

    return component;
  };

  ret.name = name;

  return ret;
};
