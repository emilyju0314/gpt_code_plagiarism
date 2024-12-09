irods::resource* plugin_factory( const std::string& _inst_name, const std::string& _context ) {

        // =-=-=-=-=-=-=-
        // 4a. create mso_resource
        mso_resource* resc = new mso_resource( _inst_name, _context );

        // =-=-=-=-=-=-=-
        // 4b. map function names to operations.  this map will be used to load
        //     the symbols from the shared object in the delay_load stage of
        //     plugin loading.
        resc->add_operation( irods::RESOURCE_OP_UNLINK,            "mso_unlink_plugin" );
        resc->add_operation( irods::RESOURCE_OP_STAGETOCACHE,      "mso_stagetocache_plugin" );
        resc->add_operation( irods::RESOURCE_OP_SYNCTOARCH,        "mso_synctoarch_plugin" );
        resc->add_operation( irods::RESOURCE_OP_RESOLVE_RESC_HIER, "mso_redirect_plugin" );
        resc->add_operation( irods::RESOURCE_OP_REBALANCE,         "mso_rebalance" );
        resc->add_operation( irods::RESOURCE_OP_MKDIR,             "mso_mkdir_plugin" );
        resc->add_operation( irods::RESOURCE_OP_RENAME,            "mso_rename_plugin" );
        resc->add_operation( irods::RESOURCE_OP_STAT,              "mso_file_stat_plugin" );
        resc->add_operation( irods::RESOURCE_OP_TRUNCATE,          "mso_truncate_plugin" );

        // =-=-=-=-=-=-=-
        // set some properties necessary for backporting to iRODS legacy code
        resc->set_property< int >( irods::RESOURCE_CHECK_PATH_PERM, 2 );//DO_CHK_PATH_PERM );
        resc->set_property< int >( irods::RESOURCE_CREATE_PATH,     1 );//CREATE_PATH );

        // =-=-=-=-=-=-=-
        // 4c. return the pointer through the generic interface of an
        //     irods::resource pointer
        return dynamic_cast<irods::resource*>( resc );

    }