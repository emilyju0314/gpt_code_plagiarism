irods::ms_table_entry*  plugin_factory( ) {
        irods::ms_table_entry* msvc = new irods::ms_table_entry( 3 );
        msvc->add_operation( "irods_msvc_test", "irods_msvc_test" );
        return msvc;
    }