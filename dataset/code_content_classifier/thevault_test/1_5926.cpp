rObject
    uobject_make_proto(const std::string& name)
    {
      CAPTURE_GLOBAL(UObject);
      rObject res =
        UObject
        ->call(SYMBOL(clone));
      res->call(SYMBOL(uobjectInit));
      res->call(SYMBOL(init));
      res->slot_set_value(SYMBOL(finalize), new object::Primitive(&uobject_finalize));
      res->slot_set_value(SYMBOL(__uobject_cname), new object::String(name));
      res->slot_set_value(SYMBOL(__uobject_base), res);
      res->slot_set_value(SYMBOL(clone), new object::Primitive(&uobject_clone));
      res->slot_set_value(SYMBOL(periodicCall), object::primitive(&periodic_call));
      return res;
    }