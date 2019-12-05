/** [bs-clean-deep] is bindings for {{: https://github.com/nunofgs/clean-deep } [clean-deep]},
    a library for removing empty or nullable values from javascript objects.

    [clean-deep] uses lodash ([isempty] and [isplainobject]) in addition to
    checking for empty and nullable values to perform the actual cleaning of
    JS-objects.
 */

/** Removing empty or nullable values from javascript objects. Set any of the
    parameters to [false] to exclude that type from being cleaned.
 */
let cleanDeep:
  (
    ~cleanKeys: array(string)=?,
    ~cleanValues: array(string)=?,
    ~emptyArrays: bool=?,
    ~emptyObjects: bool=?,
    ~emptyStrings: bool=?,
    ~nullValues: bool=?,
    ~undefinedValues: bool=?,
    Js.t('dirtyJsObject)
  ) =>
  Js.t('cleanedJsObject);
