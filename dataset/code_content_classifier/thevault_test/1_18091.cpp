error database_manager::init_from_type(
        const std::string& _type,
        const std::string& _key,
        const std::string& _inst,
        const std::string& _ctx,
        database_ptr&      _db ) {
        // =-=-=-=-=-=-=-
        // create the database plugin and add it to the table
        database_ptr ptr;
        error ret = load_database_plugin( ptr, _type, _inst, _ctx );
        if ( !ret.ok() ) {
            return PASSMSG( "Failed to load database plugin", ret );
        }

        plugins_[ _key ] = ptr;

        _db = plugins_[ _key ];

        return SUCCESS();

    }