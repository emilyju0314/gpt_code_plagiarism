void mgp_otcstore::closedeal(const name& taker, const uint64_t& deal_id) {
	require_auth( taker );

	sk_deal_t deals(_self, _self.value);
	auto deal_itr = deals.find(deal_id);
	check( deal_itr != deals.end(), "deal not found: " + to_string(deal_id) );
	check( !deal_itr->closed, "deal already closed: " + to_string(deal_id) );
    check( deal_itr -> order_taker == taker, "no permission");

	auto order_id = deal_itr->order_id;
	sell_order_t orders(_self, _self.value);
	auto order_itr = orders.find(order_id);
	check( order_itr != orders.end(), "sell order not found: " + to_string(order_id) );
	check( !order_itr->closed, "order already closed" );

	auto deal_quantity = deal_itr->deal_quantity;
	check( order_itr->frozen_quantity >= deal_quantity, "Err: order frozen quantity smaller than deal quantity" );

	orders.modify( *order_itr, _self, [&]( auto& row ) {
		row.frozen_quantity -= deal_quantity;
	});

	deals.modify( *deal_itr, _self, [&]( auto& row ) {
		row.closed = true;
		row.closed_at = time_point_sec(current_time_point());
	});

}