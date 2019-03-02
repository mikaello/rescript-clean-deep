let cleanDeep:
  (
    ~emptyArrays: bool=?,
    ~emptyObjects: bool=?,
    ~emptyStrings: bool=?,
    ~nullValues: bool=?,
    ~undefinedValues: bool=?,
    Js.t('dirtyJsObject)
  ) =>
  Js.t('cleanedJsObject);