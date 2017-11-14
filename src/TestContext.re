    let create = () => {
      val mutable data = 0;
      pub add = () => { data = data + 1; this };
      pub get = () => data;
    };

    let ctx1 = create();

    let result = ctx1#add()#get();
    (result == 1) ? Js.log("SUCCESS") : Js.log("ERROR");


    let ctx2 = create();
    let result = ctx2#add()#add()#get();
    (result == 2) ? Js.log("SUCCESS") : Js.log("ERROR");
