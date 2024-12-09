naming::gid_type agas_raw_counter_creator(
        counter_info const& info, error_code& ec, char const* const service_name)
    {
        // verify the validity of the counter instance name
        counter_path_elements paths;
        get_counter_path_elements(info.fullname_, paths, ec);
        if (ec) return naming::invalid_gid;

        if (paths.objectname_ != "agas") {
            HPX_THROWS_IF(ec, bad_parameter, "agas_raw_counter_creator",
                "unknown performance counter (unrelated to AGAS)");
            return naming::invalid_gid;
        }
        if (paths.parentinstance_is_basename_) {
            HPX_THROWS_IF(ec, bad_parameter, "agas_raw_counter_creator",
                "invalid counter instance parent name: " +
                    paths.parentinstancename_);
            return naming::invalid_gid;
        }

        // counter instance name: <agas_instance_name>/total
        // for instance: locality#0/total
        if (paths.instancename_ == "total" && paths.instanceindex_ == -1)
        {
            // find the referenced AGAS instance and dispatch the request there
            std::string service(agas::service_name);
            service += paths.parentinstancename_;

            if (-1 == paths.parentinstanceindex_) {
                HPX_THROWS_IF(ec, bad_parameter, "agas_raw_counter_creator",
                    "invalid parent instance index: -1");
                return naming::invalid_gid;
            }
            service += "#";
            service += std::to_string(paths.parentinstanceindex_);

            service += "/";
            service += service_name;

            naming::id_type id = agas::resolve_name(launch::sync, service, ec);
            if (id == naming::invalid_id) {
                HPX_THROWS_IF(ec, not_implemented,
                    "agas_raw_counter_creator",
                    "invalid counter name: " +
                        remove_counter_prefix(info.fullname_));
                return naming::invalid_gid;
            }

            return detail::retrieve_agas_counter(info.fullname_, id, ec);
        }

        HPX_THROWS_IF(ec, not_implemented, "agas_raw_counter_creator",
            "invalid counter type name: " + paths.instancename_);
        return naming::invalid_gid;
    }