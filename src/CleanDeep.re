[@bs.module]
external cleanDeep: Js.t('dirtyJsObject) => Js.t('cleanedJsObject) =
  "clean-deep";

[@bs.deriving abstract]
type cleanDeepOptions = {
  emptyArrays: bool,
  emptyObjects: bool,
  emptyStrings: bool,
  nullValues: bool,
  undefinedValues: bool,
};

[@bs.module]
external cleanDeep':
  (Js.t('dirtyJsObject), cleanDeepOptions) => Js.t('cleanedJsObject) =
  "clean-deep";

let cleanDeepWithOptions =
    (
      jsObject: Js.t('dirtyJsObject),
      ~emptyArrays: bool=true,
      ~emptyObjects: bool=true,
      ~emptyStrings: bool=true,
      ~nullValues: bool=true,
      ~undefinedValues: bool=true,
      (),
    )
    : Js.t('cleanedJsObject) => {
  let options =
    cleanDeepOptions(
      ~emptyArrays,
      ~emptyObjects,
      ~emptyStrings,
      ~nullValues,
      ~undefinedValues,
    );

  cleanDeep'(jsObject, options);
};