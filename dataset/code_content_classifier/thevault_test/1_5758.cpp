void mgp_otcstore::openorder(const name& owner, const asset& quantity, const asset& price, const asset& min_accept_quantity) {
	require_auth( owner );

	check( quantity.symbol.is_valid(), "Invalid quantity symbol name" );
	check( quantity.is_valid(), "Invalid quantity");
	check( quantity.symbol == SYS_SYMBOL, "Token Symbol not allowed" );
	check( quantity.amount > 0, "order quanity must be positive" );

	check( price.symbol.is_valid(), "Invalid quantity symbol name" );
	check( price.is_valid(), "Invalid quantity");
	check( price.symbol == CNY_SYMBOL, "Price Symbol not allowed" );
	check( price.amount > 0, "price must be positive" );

	check( min_accept_quantity.symbol == price.symbol, "min accept symbol not equal to price symbol" );

	seller_t seller(owner);
	check( _dbc.get(seller), "seller not found: " + owner.to_string() );
	check( seller.available_quantity >= quantity, "seller insufficient quantitiy to sell" );
	seller.available_quantity -= quantity;
	_dbc.set( seller );

	if (_gstate.min_pos_stake_quantity.amount > 0) {
		auto staking_con = _gstate.pos_staking_contract;
		balances bal(staking_con, staking_con.value);
		auto itr = bal.find(owner.value);
		check( itr != bal.end(), "POS staking not found for: " + owner.to_string() );
		check( itr->remaining >= _gstate.min_pos_stake_quantity, "POS Staking requirement not met" );
	}

	sell_order_t order(_self, _self.value);
	auto order_id = order.available_primary_key();
	order.emplace( _self, [&]( auto& row ) {
		row.id 					= order_id;
		row.owner 				= owner;
		row.price				= price;
		row.quantity			= quantity;
		row.min_accept_quantity = min_accept_quantity;
		row.closed				= false;
		row.created_at			= time_point_sec(current_time_point());
		row.frozen_quantity.symbol = SYS_SYMBOL;
		row.fulfilled_quantity.symbol = SYS_SYMBOL;
	});
}