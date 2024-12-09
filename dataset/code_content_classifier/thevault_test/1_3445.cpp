explicit managed_object(
        naming::gid_type const& locality
        )
      : base_type(stub_type::create_async(
            naming::id_type(locality, naming::id_type::unmanaged),
            naming::invalid_id))
    {
    }