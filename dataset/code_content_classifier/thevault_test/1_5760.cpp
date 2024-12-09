void mgp_otcstore::deposit(name from, name to, asset quantity, string memo) {
	if (to != _self) return;

	seller_t seller(from);
	_dbc.get( seller );

	if (quantity.symbol == SYS_SYMBOL){
		seller.available_quantity += quantity;
	}

	_dbc.set( seller );


}