explicit simple_object(
        naming::id_type const& locality
        )
      : base_type(stub_type::create_async(locality, naming::invalid_id))
    {
    }