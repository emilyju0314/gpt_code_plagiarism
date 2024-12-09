error database_manager::resolve(
        std::string  _key,
        database_ptr& _value ) {

        if ( _key.empty() ) {
            return ERROR( SYS_INVALID_INPUT_PARAM, "empty key" );
        }

        if ( plugins_.has_entry( _key ) ) {
            _value = plugins_[ _key ];
            return SUCCESS();

        }
        else {
            std::stringstream msg;
            msg << "no database plugin found for name ["
                << _key
                << "]";
            return ERROR( SYS_INVALID_INPUT_PARAM, msg.str() );

        }

    }