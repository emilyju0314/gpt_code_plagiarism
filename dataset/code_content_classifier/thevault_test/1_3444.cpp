explicit managed_refcnt_monitor(naming::id_type const& locality)
      : base_type()
      , flag_promise_()
      , flag_(flag_promise_.get_future())
      , locality_(naming::get_locality_from_id(locality))
    {
        static_cast<base_type&>(*this) =
            stub_type::create_async(locality_, flag_promise_.get_id());
    }