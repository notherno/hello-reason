print_endline("Hello World");
Js.log("Hello");

let score: int = 10;

/** Type of scores */
type scoreType = int;

let addInt = (x, y): scoreType => x + y;
let addFloat = (x, y) => x +. y;

Js.log(addInt(score, 2));

let me: School.person = {age: 5, name: "Big Reason"};
let meNextYear: School.person = me;

meNextYear.age = meNextYear.age + 1;

Js.log(me);
Js.log(meNextYear);

let world = {j|世界|j};
Js.log({j|こんにちは、$world|j});

type myResponseVariant =
  | Yes
  | No
  | PrettyMuch;

let areYouCrushingIt = Yes;

Js.log(
  switch (areYouCrushingIt) {
  | No => "No worries. Keep going!"
  | Yes => "Great!"
  | PrettyMuch => "Nice!"
  },
);

type account =
  | None
  | Instagram(string)
  | Facebook(string, int);

let myAccount = Facebook("Josh", 26);
let friendAccount = Instagram("Jenny");

type nullableInt = option(int);

let greeting = account =>
  switch (account) {
  | None => "Hi!"
  | Facebook(name, age) =>
    {j|Hi $name, you're |j} ++ string_of_int(age) ++ {j|-year-old.|j}
  | Instagram(name) => "Hello " ++ name ++ "!"
  };

Js.log(greeting(friendAccount));

let personHasACar = true;

let licenseNumber =
  if (personHasACar) {
    Some(5);
  } else {
    None;
  };

Js.log(licenseNumber);
Js.log(List.nth([11, 22], 0));

let greetMore = name => {
  let part1 = "Hello";
  part1 ++ " " ++ name;
};

Js.log(greetMore("Helohelo"));

/** receive & destructure the unit argument */
let logSomething = (_: unit): unit => {
  print_endline("hello");
  print_endline("world");
};

logSomething();

type result('a, 'b) =
  | Ok('a)
  | Error('b);

type myPayload = {data: string};

type myPayloadResults('errorType) = list(result(myPayload, 'errorType));

let payloadResults: myPayloadResults(string) = [
  Ok({data: "hi"}),
  Ok({data: "bye"}),
  Error("Something wrong happened!"),
];

type leftOrRight =
  | Left(int)
  | Right(int);

let i = Left(110085);

/* magic! */
let Left(v) | Right(v) = i;

Js.log(v);

exception InputClosed(string);

// raise(InputClosed("the stream has closed!"));

type tesla = {. color: string};

let obj: tesla = {pub color = "Red"};

Js.log(obj#color); /* "Red" */

Js.log("this is reason");
let x = [%bs.raw {| 'here is a string from javascript' |}];
Js.log(x ++ " back in reason land"); /* ++ is the operator for string concat */

[@bs.val] external pi: float = "Math.PI";

Js.log(pi);
