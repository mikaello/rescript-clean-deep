[@bs.deriving abstract]
type cleanDeepOptions = {
  cleanKeys: array(string),
  cleanValues: array(string),
  emptyArrays: bool,
  emptyObjects: bool,
  emptyStrings: bool,
  nullValues: bool,
  undefinedValues: bool,
};

[@bs.module]
external cleanDeep:
  (Js.t('dirtyJsObject), cleanDeepOptions) => Js.t('cleanedJsObject) =
  "clean-deep";

let cleanDeep =
    (
      ~cleanKeys: array(string)=[||],
      ~cleanValues: array(string)=[||],
      ~emptyArrays: bool=true,
      ~emptyObjects: bool=true,
      ~emptyStrings: bool=true,
      ~nullValues: bool=true,
      ~undefinedValues: bool=true,
      jsObject: Js.t('dirtyJsObject),
    )
    : Js.t('cleanedJsObject) => {
  let options =
    cleanDeepOptions(
      ~cleanKeys,
      ~cleanValues,
      ~emptyArrays,
      ~emptyObjects,
      ~emptyStrings,
      ~nullValues,
      ~undefinedValues,
    );

  cleanDeep(jsObject, options);
};
