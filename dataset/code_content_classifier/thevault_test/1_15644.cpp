void apply( uint64_t code, uint64_t action ) {
       if( code == N(currency) ) {
          if( action == N(transfer) ) {
             apply_transfer(code, current_message<currency::transfer>());
          }
       } else if ( code == N(eos) ) {
          if( action == N(transfer) ) {
             apply_transfer(code, current_message<eosio::transfer>());
          }
       } else if (code == N(proxy) ) {
          if ( action == N(setowner)) {
             apply_setowner(current_message<set_owner>());
          }
       }
    }