ACTION reporting::received( name buyer, uint64_t orderKey, bool done ) {
	require_auth( buyer );
	user_t users( _self, _self.value );
	auto it_buyer = users.find(buyer.value);
	check( !(it_buyer == users.end()) , "Please enrol first." );
	check( !(it_buyer->frozen) , "Your account is frozen." );

	order_t order( _self, _self.value );
	auto it_order = order.find(orderKey);
	check( !(it_order == order.end()), "No such order." );
	check( it_order->buyer == buyer, "That's not your order." );
	
	if (done) { 
	  order.modify(it_order, _self, [&]( auto& row ) { 
	    row.received = 1; 
	  }); 
	}
	else { 
	  std::string reason = "Order " + std::to_string(orderKey) + " not received.";
	  reporting::blameintern(buyer, it_order->seller, reason, 1);
	}
}