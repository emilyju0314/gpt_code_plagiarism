irods::resource* plugin_factory( const std::string& _inst_name, const std::string& _context ) {

        // =-=-=-=-=-=-=-
        // 4a. create examplefilesystem_resource
        examplefilesystem_resource* resc = new examplefilesystem_resource( _inst_name, _context );

        // =-=-=-=-=-=-=-
        // 4b. map function names to operations.  this map will be used to load
        //     the symbols from the shared object in the delay_load stage of
        //     plugin loading.
        resc->add_operation( irods::RESOURCE_OP_CREATE,       "example_file_create_plugin" );
        resc->add_operation( irods::RESOURCE_OP_OPEN,         "example_file_open_plugin" );
        resc->add_operation( irods::RESOURCE_OP_READ,         "example_file_read_plugin" );
        resc->add_operation( irods::RESOURCE_OP_WRITE,        "example_file_write_plugin" );
        resc->add_operation( irods::RESOURCE_OP_CLOSE,        "example_file_close_plugin" );
        resc->add_operation( irods::RESOURCE_OP_UNLINK,       "example_file_unlink_plugin" );
        resc->add_operation( irods::RESOURCE_OP_STAT,         "example_file_stat_plugin" );
        resc->add_operation( irods::RESOURCE_OP_LSEEK,        "example_file_lseek_plugin" );
        resc->add_operation( irods::RESOURCE_OP_MKDIR,        "example_file_mkdir_plugin" );
        resc->add_operation( irods::RESOURCE_OP_RMDIR,        "example_file_rmdir_plugin" );
        resc->add_operation( irods::RESOURCE_OP_OPENDIR,      "example_file_opendir_plugin" );
        resc->add_operation( irods::RESOURCE_OP_CLOSEDIR,     "example_file_closedir_plugin" );
        resc->add_operation( irods::RESOURCE_OP_READDIR,      "example_file_readdir_plugin" );
        resc->add_operation( irods::RESOURCE_OP_RENAME,       "example_file_rename_plugin" );
        resc->add_operation( irods::RESOURCE_OP_TRUNCATE,     "example_file_truncate_plugin" );
        resc->add_operation( irods::RESOURCE_OP_FREESPACE,    "example_file_get_fsfreespace_plugin" );
        resc->add_operation( irods::RESOURCE_OP_STAGETOCACHE, "example_file_stagetocache_plugin" );
        resc->add_operation( irods::RESOURCE_OP_SYNCTOARCH,   "example_file_synctoarch_plugin" );
        resc->add_operation( irods::RESOURCE_OP_REGISTERED,   "example_file_registered_plugin" );
        resc->add_operation( irods::RESOURCE_OP_UNREGISTERED, "example_file_unregistered_plugin" );
        resc->add_operation( irods::RESOURCE_OP_MODIFIED,     "example_file_modified_plugin" );
        resc->add_operation( irods::RESOURCE_OP_NOTIFY,       "example_file_notify_plugin" );

        resc->add_operation( irods::RESOURCE_OP_RESOLVE_RESC_HIER,     "example_file_redirect_plugin" );
        resc->add_operation( irods::RESOURCE_OP_REBALANCE,             "example_file_rebalance" );

        // =-=-=-=-=-=-=-
        // set some properties necessary for backporting to iRODS legacy code
        resc->set_property< int >( irods::RESOURCE_CHECK_PATH_PERM, 2 );//DO_CHK_PATH_PERM );
        resc->set_property< int >( irods::RESOURCE_CREATE_PATH,     1 );//CREATE_PATH );

        // =-=-=-=-=-=-=-
        // 4c. return the pointer through the generic interface of an
        //     irods::resource pointer
        return dynamic_cast<irods::resource*>( resc );

    }