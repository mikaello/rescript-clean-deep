open RescriptCleanDeep

Console.log("Demo of 'rescript-clean-deep'\n")

let s = %raw(` { emptystring: '', foo: 3, emptyobject: {} } `)

Console.log("No options:")
Console.log(CleanDeep.cleanDeep(s, ()))

Console.log("\nWith empty objects preserved:")
Console.log(s -> CleanDeep.cleanDeep(~emptyObjects=false, ()))

Console.log("\nWith empty objects and strings preserved:")
Console.log(CleanDeep.cleanDeep(s, ~emptyObjects=false, ~emptyStrings=false, ()))
