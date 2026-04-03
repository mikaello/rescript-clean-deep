@ocaml.doc(" [rescript-clean-deep] provides bindings for {{: https://github.com/nunofgs/clean-deep } [clean-deep]},
    a library for removing empty or nullable values from javascript objects.

    [clean-deep] uses lodash ([isEmpty] and [isPlainObject]) in addition to
    checking for empty and nullable values to perform the actual cleaning of
    JS-objects.
 ")
@ocaml.doc(" Removing empty or nullable values from javascript objects. Set any of the
    parameters to [false] to exclude that type from being cleaned.
 ")
let cleanDeep: (
  'dirtyJsObject,
  ~cleanKeys: array<string>=?,
  ~cleanValues: array<string>=?,
  ~emptyArrays: bool=?,
  ~emptyObjects: bool=?,
  ~emptyStrings: bool=?,
  ~nullValues: bool=?,
  ~undefinedValues: bool=?,
  ~naNValues: bool=?,
  unit,
) => 'cleanedJsObject
