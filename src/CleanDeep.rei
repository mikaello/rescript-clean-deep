type cleanDeepOptions;

let cleanDeepWithOptions:
  (
    Js.t('dirtyJsObject),
    ~emptyArrays: bool=?,
    ~emptyObjects: bool=?,
    ~emptyStrings: bool=?,
    ~nullValues: bool=?,
    ~undefinedValues: bool=?,
    unit
  ) =>
  Js.t('cleanedJsObject);

[@bs.module]
external cleanDeep: Js.t('dirtyJsObject) => Js.t('cleanedJsObject) =
  "clean-deep";