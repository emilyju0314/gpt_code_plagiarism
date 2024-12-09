static void
    maybe_add(std::vector<libport::Symbol>& control, List::value_type& l,
              libport::Symbol slot_name)
    {
      if (!libport::has(control, slot_name))
      {
        control.push_back(slot_name);
        l.push_back(new String(slot_name));
      }
    }