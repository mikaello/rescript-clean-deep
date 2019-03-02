# (WIP) bs-clean-deep

[![Build Status](https://travis-ci.org/mikaello/bs-clean-deep.svg?branch=master)](https://travis-ci.org/mikaello/bs-clean-deep)

🚧 **UNDER CONSTRUCTION** 🚧

Bindings for [clean-deep](https://github.com/nunofgs/clean-deep), a library for removing empty or nullable values from javascript objects.

## Getting started

```
yarn add bs-clean-deep
```

Then add `bs-clean-deep` as a dependency to `bsconfig.json`:

```diff
"bs-dependencies": [
+  "bs-clean-deep"
]
```

## Example

```reason
open BsCleanDeep;

let jsObject = [%bs.raw {|
{
  bar: {},
  baz: null,
  biz: 'baz',
  foo: '',
  net: [],
  nit: undefined,
  qux: {
    baz: 'boz',
    txi: ''
  }
}
|}];

let cleaned = CleanDeep.cleanDeep(jsObject);

Js.log(cleaned);
/* => { biz: 'baz', qux: { baz: 'boz' } } */

let cleaned_keep_strings = jsObject |> CleanDeep.cleanDeep(~emptyStrings=false);

Js.log(cleaned_keep_strings);
/* => { biz: 'baz', foo: '', qux: { baz: 'boz', txi: '' } } */
```

## Contribute

If you find bugs or there are updates in [clean-deep](https://github.com/nunofgs/clean-deep), feel free to open an issue or PR. If you are upgrading any dependencies, please use yarn so `yarn.lock` is updated.
