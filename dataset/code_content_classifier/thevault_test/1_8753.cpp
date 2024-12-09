ACTION reporting::sent( name seller, uint64_t orderKey ) {
	require_auth( seller );
	user_t users( _self, _self.value );
	auto it_seller = users.find(seller.value);
	check( !(it_seller == users.end()) , "Please enrol first." );
	check( !(it_seller->frozen) , "Your account is frozen." );

	order_t order( _self, _self.value );
	auto it_order = order.find(orderKey);
	check( !(it_order == order.end()), "No such order." );
	check( it_order->seller == seller, "That's not your order." );

	order.modify(it_order, _self, [&]( auto& row ) { 
	  row.sent = 1; 
	}); 
}