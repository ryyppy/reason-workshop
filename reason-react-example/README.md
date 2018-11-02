# ReasonReact Workshop Exercise

This is based on the [@ryyppy/antwar-default](https://github.com/ryyppy/antwar-default) boilerplate.

## How to use

**Install Project dependencies:**

```
npm install
```

**BuckleScript related tasks:**

Linux / MacOS Users:

```
# Build Reason sources
npm run bs:build

# Run in watch mode
npm run bs:watch
```

Windows Users:

```
npm run win:bs:build
npm run win:bs:watch
```

**Antwar related tasks:**

```
# Start server for development
npm start

# Build the website in production mode
npm run build
```

## Deployment

**Netlify:**

- Add your project to netlify
- Define following build task: `npm run netlify`
- Define `build/`as your output folder


## Known Issues

There is currently a problem with mdx yielding following error:

```
npm run build
Warning: React does not recognize the `metaString` prop on a DOM element. If you intentionally want it to appear in the DOM as a custom attribute, spell it as lowercase `metastring` instead. If you accidentally passed it from a parent component, remove it from the DOM element.
    in code
    in MDXTag
    in Context.Consumer
    in Unknown
    in pre
    in MDXTag
    in Context.Consumer
    in Unknown
    in div
    in MDXTag
    in Context.Consumer
    in Unknown
    in _default
    in Fragment
    in Layout
    in SiteBody
    in Unknown
    in Route
    in Router
    in StaticRouter
```

Relevant discussion on mdxjs: [PR](https://github.com/mdx-js/mdx/pull/294)

This is just a warning and will not break your app.



