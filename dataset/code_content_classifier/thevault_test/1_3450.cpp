naming::gid_type per_action_data_counter_creator(counter_info const& info,
        hpx::parcelset::detail::per_action_data_counter_registry& registry,
        hpx::util::function_nonser<
            std::int64_t(std::string const&, bool)
        > const& counter_func,
        error_code& ec)
    {
        switch (info.type_) {
        case counter_raw:
            {
                counter_path_elements paths;
                get_counter_path_elements(info.fullname_, paths, ec);
                if (ec) return naming::invalid_gid;

                if (paths.parentinstance_is_basename_) {
                    HPX_THROWS_IF(ec, bad_parameter,
                        "per_action_data_counter_creator",
                        "invalid action invocation counter name (instance name "
                        "must not be a valid base counter name)");
                    return naming::invalid_gid;
                }

                if (paths.parameters_.empty()) {
                    // if no parameters (action name) is given assume that this
                    // counter should report the overall value for all actions
                    using util::placeholders::_1;
                    auto const& f =
                        util::bind(counter_func, paths.parameters_, _1);
                    return performance_counters::locality_raw_counter_creator(
                        info, f,ec);
                }

                // ask registry
                hpx::util::function_nonser<std::int64_t(bool)> f =
                    registry.get_counter(paths.parameters_, counter_func);

                return detail::create_raw_counter(info, std::move(f), ec);
            }
            break;

        default:
            HPX_THROWS_IF(ec, bad_parameter,
                "per_action_data_counter_creator",
                "invalid counter type requested");
            return naming::invalid_gid;
        }
    }