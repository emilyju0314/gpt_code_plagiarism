irods::api_entry* plugin_factory(
        const std::string&,    // _inst_name
        const std::string& ) { //_context
        // =-=-=-=-=-=-=-
        // create a api def object
        irods::apidef_t def = { SET_RR_CTX_AN,
                                RODS_API_VERSION,
                                LOCAL_USER_AUTH,
                                LOCAL_USER_AUTH,
                                "SetRoundRobinContextInp_PI", 0,
                                NULL, 0,
                                0, 0
                              }; // null fcn ptr, handled in delay_load
        // =-=-=-=-=-=-=-
        // create an api object
        irods::api_entry* api = new irods::api_entry( def );

        // =-=-=-=-=-=-=-
        // assign the fcn which will handle the api call
#ifdef RODS_SERVER
        api->fcn_name_ = "set_round_robin_context";

#endif // RODS_SERVER

        // =-=-=-=-=-=-=-
        // assign the pack struct key and value
        api->in_pack_key   = "SetRoundRobinContextInp_PI";
        api->in_pack_value = SetRoundRobinContextInp_PI;

        // =-=-=-=-=-=-=-
        // and... were done.
        return api;

    }