ACTION reporting::buy( name buyer, uint64_t itemKey ) {
	require_auth( buyer );
	user_t users( _self, _self.value );
	auto it_buyer = users.find(buyer.value);
	check( !(it_buyer == users.end()) , "Please enrol first." );
	check( !(it_buyer->frozen) , "Your account is frozen." );

	item_t item( _self, _self.value );
	auto it_item = item.find(itemKey);
	check( !(it_item == item.end()), "No such item" );
	check( !(it_item->appliable), "Application for this item is not yet done." );
	check( !(it_item->voteable), "Voting for this item is not yet done." );
	check( !(it_item->reporter == buyer), "You cannot buy for your own item." );
	check( !(it_item->rating/1000000000 == 0), "This item does not meet quality requirements to be sold." );
	
	name seller = it_item->reporter;
	uint64_t price = it_item->price;
	
	order_t order( _self, _self.value );
	for(auto& row : order) { 
	  check( !(row.itemKey == itemKey && row.buyer == buyer), "That order was already placed." ); 
	}
	order.emplace(_self, [&]( auto& row ) { 
	  row.key = order.available_primary_key();  
	  row.itemKey = itemKey;
	  row.seller = seller;
	  row.buyer = buyer; 
	  row.sent = 0;
	  row.received = 0; 
	});
	if(price > 0) {
	  reporting::transfer(buyer, seller, price);
	}
}