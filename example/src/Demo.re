open BsCleanDeep;

Js.log("Demo of 'bs-clean-deep'\n");

let s = [%bs.raw {| { emptystring: '', foo: 3, emptyobject: {} } |}];

Js.log("No options:");
Js.log(CleanDeep.cleanDeep(s));

Js.log("\nWith empty objects preserved:");
Js.log(s |> CleanDeep.cleanDeep(~emptyObjects=false));

Js.log("\nWith empty objects and strings preserved:");
Js.log(CleanDeep.cleanDeep(~emptyObjects=false, ~emptyStrings=false, s));