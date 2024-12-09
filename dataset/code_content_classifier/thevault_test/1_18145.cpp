irods::error mso_stagetocache_plugin(
        irods::resource_plugin_context& _ctx,
        const char*                     _cache_file_name ) {
        using namespace boost;
        namespace fs = boost::filesystem;

        // =-=-=-=-=-=-=-
        // ensure we have a valid plugin context
        irods::error ret = _ctx.valid< irods::file_object >();
        if ( !ret.ok() ) {
            return PASS( ret );
        }

        // =-=-=-=-=-=-=-
        // get the file_object from the context
        irods::file_object_ptr fco = boost::dynamic_pointer_cast <
                                     irods::file_object > ( _ctx.fco() );

        // =-=-=-=-=-=-=-
        // look for the magic token in the physical path
        std::string phy_path = fco->physical_path();
        size_t      pos      = phy_path.find_first_of( ":" );
        if ( std::string::npos == pos ) {
            std::string msg( "[:] not found in physical path for mso [" );
            msg += phy_path + "]";
            return ERROR(
                       MICRO_SERVICE_OBJECT_TYPE_UNDEFINED,
                       msg );
        }

        // =-=-=-=-=-=-=-
        // remove the first two chars from the phy path
        phy_path = phy_path.substr( 2, std::string::npos );

        // =-=-=-=-=-=-=-
        // substr the phy path to the : per
        // the syntax of an mso registered phy path
        std::string call_code = phy_path.substr( 0, pos - 2 );

        // =-=-=-=-=-=-=-
        // build a string to call the microservice per mso syntax
        std::string call_str( "msiobjget_" );
        call_str += call_code;
        call_str += "(\"" + phy_path + "\",";
        call_str += "\""  + lexical_cast< std::string >( fco->mode() ) + "\",";
        call_str += "\""  + lexical_cast< std::string >( fco->flags() ) + "\",";
        call_str += "\"";
        call_str += _cache_file_name;
        call_str += "\")";

        // =-=-=-=-=-=-=-
        // prepare necessary artifacts for invocation of the rule engine
        ruleExecInfo_t rei;
        msParamArray_t ms_params;
        memset( &rei, 0, sizeof( ruleExecInfo_t ) );
        memset( &ms_params, 0, sizeof( msParamArray_t ) );

        rei.rsComm = _ctx.comm();
        if ( _ctx.comm() != NULL ) {
            rei.uoic = &_ctx.comm()->clientUser;
            rei.uoip = &_ctx.comm()->proxyUser;
        }

        // =-=-=-=-=-=-=-
        // call the microservice via the rull engine
        int status = applyRule(
                         const_cast<char*>( call_str.c_str() ),
                         &ms_params,
                         &rei,
                         NO_SAVE_REI );

        // =-=-=-=-=-=-=-
        // handle error condition, rei may have more info
        if ( status < 0 ) {
            if ( rei.status < 0 ) {
                status = rei.status;
            }

            return ERROR( status,
                          call_str );

        }

        // =-=-=-=-=-=-=-
        // win?
        return SUCCESS();

    }