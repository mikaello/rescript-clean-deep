open Jest;
open Expect;

describe("cleanDeep()", () =>
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
          net: '',
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
  })
);