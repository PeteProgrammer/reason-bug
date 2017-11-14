module ContextMap = Map.Make(String);

type t = {.
  add: 'a. string => 'a => t,
  get: 'a. string => 'a
};

let create = (metaData) : t => {
  val data = ref(metaData);
  pub add : 'a. string => 'a => t = (key,x) => { data := data^ |> ContextMap.add(key, Obj.repr(x)); this };
  pub get : 'a. string => 'a = (key) => data^ |> ContextMap.find(key) |> Obj.obj;
  };

let ctx1 = create(ContextMap.empty);

let result : int = ctx1#add("key", 42)#get("key");
(result == 42) ? Js.log("SUCCESS") : Js.log("ERROR");


let ctx2 = create(ContextMap.empty);
let result : int = ctx2#add("key", 42)#add("key", 43)#get("key");
(result == 42) ? Js.log("SUCCESS") : Js.log("ERROR");
