void notify_worker(notification_header const& header)
{
    // This lock acquires the bbb mutex on creation. When it goes out of scope,
    // it's dtor calls big_boot_barrier::notify().
    big_boot_barrier::scoped_lock lock(get_big_boot_barrier());

    // register all ids with this locality
    header.ids.register_ids_on_worker_loc();

    runtime& rt = get_runtime();
    naming::resolver_client& agas_client = rt.get_agas_client();

    if (HPX_UNLIKELY(agas_client.get_status() != state_starting))
    {
        std::ostringstream strm;
        strm << "locality " << rt.here() << " has launched early";
        HPX_THROW_EXCEPTION(internal_server_error,
            "agas::notify_worker",
            strm.str());
    }

    util::runtime_configuration& cfg = rt.get_config();

    // set our prefix
    agas_client.set_local_locality(header.prefix);
    agas_client.register_console(header.agas_endpoints);
    cfg.parse("assigned locality",
        boost::str(boost::format("hpx.locality!=%1%")
                  % naming::get_locality_id_from_gid(header.prefix)));

    // store the full addresses of the agas servers in our local service
    agas_client.component_ns_.reset(
        new detail::hosted_component_namespace(header.component_ns_address));
    agas_client.locality_ns_.reset(
        new detail::hosted_locality_namespace(header.locality_ns_address));
    naming::gid_type const& here = hpx::get_locality();

    // register runtime support component
    naming::gid_type runtime_support_gid(header.prefix.get_msb()
      , rt.get_runtime_support_lva());
    naming::address const runtime_support_address(here
      , components::get_component_type<components::server::runtime_support>()
      , rt.get_runtime_support_lva());
    agas_client.bind_local(runtime_support_gid, runtime_support_address);

    runtime_support_gid.set_lsb(std::uint64_t(0));
    agas_client.bind_local(runtime_support_gid, runtime_support_address);

    naming::gid_type const memory_gid(header.prefix.get_msb()
      , rt.get_memory_lva());
    naming::address const memory_address(here
      , components::get_component_type<components::server::memory>()
      , rt.get_memory_lva());
    agas_client.bind_local(memory_gid, memory_address);

    // Assign the initial parcel gid range to the parcelport. Note that we can't
    // get the parcelport through the parcelhandler because it isn't up yet.
    naming::gid_type parcel_lower, parcel_upper;
    agas_client.get_id_range(1000, parcel_lower, parcel_upper);

    rt.get_id_pool().set_range(parcel_lower, parcel_upper);

    // store number of initial localities
    cfg.set_num_localities(header.num_localities);

    // store number of used cores by other localities
    cfg.set_first_used_core(header.used_cores);
    rt.assign_cores();

#if defined(HPX_HAVE_SECURITY)
    // initialize certificate store
    rt.store_root_certificate(header.root_certificate);

    // initiate second round trip to root
    registration_header_security hdr(
        header.prefix
      , rt.here()
      , rt.get_certificate_signing_request());

    get_big_boot_barrier().apply(
        naming::get_locality_id_from_gid(header.prefix)
      , 0
      , header.agas_locality
      , register_worker_security_action()
      , std::move(hdr));
#endif
}