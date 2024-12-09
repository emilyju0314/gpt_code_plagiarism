irods::api_entry* plugin_factory(
        const std::string&,     //_inst_name
        const std::string& ) { // _context
        // =-=-=-=-=-=-=-
        // create a api def object
        irods::apidef_t def = { 1300,
                                RODS_API_VERSION,
                                NO_USER_AUTH,
                                NO_USER_AUTH,
                                "HelloInp_PI", 0,
                                "HelloOut_PI", 0,
                                0, // null fcn ptr, handled in delay_load
                                0  // null clear fcn
                              };
        // =-=-=-=-=-=-=-
        // create an api object
        irods::api_entry* api = new irods::api_entry( def );

#ifdef RODS_SERVER
        api->fcn_name_ = "rs_hello_world";
#endif // RODS_SERVER

        // =-=-=-=-=-=-=-
        // assign the pack struct key and value
        api->in_pack_key   = "HelloInp_PI";
        api->in_pack_value = HelloInp_PI;

        api->out_pack_key   = "HelloOut_PI";
        api->out_pack_value = HelloOut_PI;

        api->extra_pack_struct[ "OtherOut_PI" ] = OtherOut_PI;

        return api;

    }