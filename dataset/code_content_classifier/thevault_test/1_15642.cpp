void apply( uint64_t code, uint64_t action ) {
       if( code == N(currency) ) {
          if( action == N(transfer) ) 
             TOKEN_NAME::apply_currency_transfer( current_message< TOKEN_NAME::transfer >() );
       }
    }