ACTION reporting::approve(uint64_t key) {
		require_auth( "bsi"_n );
		item_t item( _self, _self.value );
		auto iterator = item.find(key);
		check( !(iterator == item.end()), "No such item on the blockchain.");
		item.modify(iterator, _self, [&]( auto& row ) { 
		  row.approval = 1; 
		});
}