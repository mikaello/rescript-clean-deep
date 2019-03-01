open Jest;
open Expect;

describe("cleanDeep()", () => {
  test("should pick defined values from the object", () => {
    let jsObject = [%bs.raw
      {|
      {
        bar: {},
        biz: [],
        foo: {
          bar: undefined,
          baz: true,
          biz: false,
          buz: null,
          net: "",
          qux: 100

        }
      }
      |}
    ];

    expect(CleanDeep.cleanDeep(jsObject))
    |> toEqual(
         [%bs.raw
           {|
            {
              foo: {
                baz: true,
                biz: false,
                qux: 100
              }
            }
           |}
         ],
       );
  });

  test("should clean arrays", () => {
    let jsObject = [%bs.raw
      {|
      {
        foo: [{
          bar: undefined,
          baz: "",
          biz: 0
        }]
      }
      |}
    ];

    expect(CleanDeep.cleanDeep(jsObject))
    |> toEqual(
         [%bs.raw
           {|
           {
             foo: [{
               biz: 0
             }]
           }
          |}
         ],
       );
  });

  test("should include non plain objects", () => {
    let jsObject = [%bs.raw
      {|
      {
        foo: {
          bar: new Date(0),
          biz: undefined
        }
      }
      |}
    ];

    expect(CleanDeep.cleanDeep(jsObject))
    |> toEqual(
         [%bs.raw
           {|
           {
             foo: {
               bar: new Date(0)
             }
           }
           |}
         ],
       );
  });

  test("should include empty objects if `emptyObjects` is `false`", () => {
    let jsObject = [%bs.raw
      {|
      {
        biz: {
          baz: 123
        },
        foo: {
          bar: {}
        }
      }
      |}
    ];

    expect(CleanDeep.cleanDeepWithOptions(jsObject, ~emptyObjects=false, ()))
    |> toEqual(
         [%bs.raw
           {|
           {
             biz: {
               baz: 123
             },
             foo: {
               bar: {}
             }
           }
           |}
         ],
       );
  });

  test("should include empty arrays if `emptyArrays` is `false`", () => {
    let jsObject = [%bs.raw
      {|
      {
        biz: {
          bar: [],
          baz: 123
        },
        foo: []
      }
      |}
    ];

    expect(CleanDeep.cleanDeepWithOptions(jsObject, ~emptyArrays=false, ()))
    |> toEqual(
         [%bs.raw
           {|
           {
             biz: {
               bar: [],
               baz: 123
             },
             foo: []
           }
           |}
         ],
       );
  });

  test("should include empty strings if `emptyStrings` is `false`", () => {
    let jsObject = [%bs.raw
      {|
      {
        foo: {
          bar: "",
          biz: 123
        }
      }
      |}
    ];

    expect(CleanDeep.cleanDeepWithOptions(jsObject, ~emptyStrings=false, ()))
    |> toEqual(
         [%bs.raw
           {|
           {
             foo: {
               bar: "",
               biz: 123
             }
           }
           |}
         ],
       );
  });

  test("should include null values if `nullValues` is `false`", () => {
    let jsObject = [%bs.raw
      {|
      {
        foo: {
          bar: null,
          biz: 123
        }
      }
      |}
    ];

    expect(CleanDeep.cleanDeepWithOptions(jsObject, ~nullValues=false, ()))
    |> toEqual(
         [%bs.raw
           {|
           {
             foo: {
               bar: null,
               biz: 123
             }
           }
           |}
         ],
       );
  });

  test("should include undefined values if `undefinedValues` is `false`", () => {
    let jsObject = [%bs.raw
      {|
      {
        foo: {
          bar: undefined,
          biz: 123,
          qux: [
            undefined,
            {},
            true
          ]
        }
      }
      |}
    ];

    expect(
      CleanDeep.cleanDeepWithOptions(jsObject, ~undefinedValues=false, ()),
    )
    |> toEqual(
         [%bs.raw
           {|
           {
             foo: {
               bar: undefined,
               biz: 123,
               qux: [
                 undefined,
                 true
               ]
             }
           }
           |}
         ],
       );
  });
});