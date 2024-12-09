naming::gid_type statistics_counter_creator(counter_info const& info,
        error_code& ec)
    {
        switch (info.type_) {
        case counter_aggregating:
            {
                counter_path_elements paths;
                get_counter_path_elements(info.fullname_, paths, ec);
                if (ec) return naming::invalid_gid;

                if (!paths.parentinstance_is_basename_) {
                    HPX_THROWS_IF(ec, bad_parameter,
                        "statistics_counter_creator", "invalid aggregate counter "
                            "name (instance name must be valid base counter name)");
                    return naming::invalid_gid;
                }

                std::string base_name;
                get_counter_name(paths.parentinstancename_, base_name, ec);
                if (ec) return naming::invalid_gid;

                std::vector<std::int64_t> parameters;
                if (!paths.parameters_.empty()) {
                    // try to interpret the additional parameter as interval
                    // time (ms)
                    namespace qi = boost::spirit::qi;
                    if (!qi::parse(paths.parameters_.begin(), paths.parameters_.end(),
                            qi::int_ % ',', parameters))
                    {
                        HPX_THROWS_IF(ec, bad_parameter,
                            "statistics_counter_creator",
                            "invalid parameter specification for counter: " +
                                paths.parameters_);
                        return naming::invalid_gid;
                    }
                }
                else {
                    parameters.push_back(1000);       // sample interval
                    parameters.push_back(10);         // rolling window
                }
                return create_statistics_counter(info, base_name, parameters, ec);
            }
            break;

        default:
            HPX_THROWS_IF(ec, bad_parameter, "statistics_counter_creator",
                "invalid counter type requested");
            return naming::invalid_gid;
        }
    }