rObject
    Primitive::apply(rList args)
    {
      if (args->value_get().empty())
        RAISE("list of arguments must begin with `this'");
      objects_type a = args->value_get();
      return
        eval::call_apply(::kernel::runner(), this, SYMBOL(apply), a);
    }