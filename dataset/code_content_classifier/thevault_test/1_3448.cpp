void component_namespace::register_counter_types(
    error_code& ec
    )
{
    using hpx::util::placeholders::_1;
    using hpx::util::placeholders::_2;
    boost::format help_count(
        "returns the number of invocations of the AGAS service '%s'");
    boost::format help_time(
        "returns the overall execution time of the AGAS service '%s'");
    performance_counters::create_counter_func creator(
        util::bind(&performance_counters::agas_raw_counter_creator, _1, _2
      , agas::server::component_namespace_service_name));

    for (std::size_t i = 0;
          i != detail::num_component_namespace_services;
          ++i)
    {
        // global counters are handled elsewhere
        if (detail::component_namespace_services[i].code_ ==
            component_ns_statistics_counter)
            continue;

        std::string name(detail::component_namespace_services[i].name_);
        std::string help;
        std::string::size_type p = name.find_last_of('/');
        HPX_ASSERT(p != std::string::npos);

        if (detail::component_namespace_services[i].target_ ==
             detail::counter_target_count)
            help = boost::str(help_count % name.substr(p+1));
        else
            help = boost::str(help_time % name.substr(p+1));

        performance_counters::install_counter_type(
            agas::performance_counter_basename + name
          , performance_counters::counter_raw
          , help
          , creator
          , &performance_counters::locality0_counter_discoverer
          , HPX_PERFORMANCE_COUNTER_V1
          , detail::component_namespace_services[i].uom_
          , ec
          );
        if (ec) return;
    }
}