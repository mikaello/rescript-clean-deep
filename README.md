# rescript-clean-deep

[![NPM version](http://img.shields.io/npm/v/rescript-clean-deep.svg)](https://www.npmjs.org/package/rescript-clean-deep)
[![Build Status](https://github.com/mikaello/rescript-clean-deep/actions/workflows/build-and-test.yml/badge.svg)](https://github.com/mikaello/rescript-clean-deep/actions/workflows/build-and-test.yml)

ReScript bindings for [clean-deep](https://github.com/nunofgs/clean-deep), a library for
removing empty or nullable values from javascript objects.

## Getting started

```
yarn add rescript-clean-deep
```

Then add `rescript-clean-deep` as a dependency to `rescript.json`:

```diff
"dependencies": [
+  "rescript-clean-deep"
]
```

## Example

```rescript
open RescriptCleanDeep

let jsObject = %raw(`
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
`)

let cleaned = CleanDeep.cleanDeep(jsObject, ())

Console.log(cleaned)
// => { biz: 'baz', qux: { baz: 'boz' } }

let cleanedKeepStrings = jsObject->CleanDeep.cleanDeep(~emptyStrings=false, ())

Console.log(cleanedKeepStrings)
// => { biz: 'baz', foo: '', qux: { baz: 'boz', txi: '' } }

let cleanedCustomValues = jsObject->CleanDeep.cleanDeep(~cleanValues=["baz"], ())

Console.log(cleanedCustomValues)
// => { qux: { baz: 'boz' } }
```

See also [example-project](./example).

## Contribute

If you find bugs or there are updates in
[clean-deep](https://github.com/nunofgs/clean-deep), feel free to open an issue
or PR.
If you are upgrading any dependencies, please use yarn so `yarn.lock` is
updated.
