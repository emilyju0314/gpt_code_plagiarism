void register_worker_security(registration_header_security const& header)
{
    // This lock acquires the bbb mutex on creation. When it goes out of scope,
    // it's dtor calls big_boot_barrier::notify().
    big_boot_barrier::scoped_lock lock(get_big_boot_barrier());

    runtime& rt = get_runtime();
    naming::resolver_client& agas_client = rt.get_agas_client();

    if (HPX_UNLIKELY(agas_client.is_connecting()))
    {
        HPX_THROW_EXCEPTION(
            internal_server_error
          , "agas::register_worker"
          , "runtime_mode_connect can't find running application.");
    }

    if (HPX_UNLIKELY(!agas_client.is_bootstrap()))
    {
        HPX_THROW_EXCEPTION(
            internal_server_error
          , "agas::register_worker"
          , "registration parcel received by non-bootstrap locality.");
    }

    notification_header_security hdr(
        rt.get_certificate()
      , rt.sign_certificate_signing_request(header.csr));

    parcelset::locality dest;
    parcelset::locality here = bbb.here();
    for (parcelset::locality const& loc : header.endpoints)
    {
        if(loc.get_type() == here.get_type())
        {
            dest = loc;
            break;
        }
    }

    // TODO: Handle cases where localities try to connect to AGAS while it's
    // shutting down.
    if (agas_client.get_status() != starting)
    {
        // We can just send the parcel now, the connecting locality isn't a part
        // of startup synchronization.
        get_big_boot_barrier().apply(
            0
          , naming::get_locality_id_from_gid(header.prefix)
          , dest
          , notify_worker_security_action()
          , std::move(hdr));
    }

    else
    {
        // AGAS is starting up; this locality is participating in startup
        // synchronization.
        util::unique_function_nonser<void()>* thunk =
                new util::unique_function_nonser<void()>(
            util::bind(
                util::one_shot(&big_boot_barrier::apply)
              , std::ref(get_big_boot_barrier())
              , 0
              , naming::get_locality_id_from_gid(header.prefix)
              , notify_worker_security_action()
              , std::move(hdr)));
        get_big_boot_barrier().add_thunk(thunk);
    }
}