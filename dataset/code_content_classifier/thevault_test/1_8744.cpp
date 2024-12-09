ACTION reporting::updateprice(name reporter, uint64_t itemKey, uint64_t price) {
  require_auth( reporter );
	user_t users( _self, _self.value );
	auto it_reporter = users.find(reporter.value);
	check( !(it_reporter == users.end()), "No such user on the blockchain.");
	check( !(it_reporter->frozen), "This user is frozen.");
  
  item_t item( _self, _self.value );
	auto it_item = item.find(itemKey);
	check( !(it_item == item.end()), "No such item on the blockchain.");
	check( it_item->reporter == reporter, "Cannot set price for items owned by other users.");
	item.modify(it_item, _self, [&]( auto& row ) { 
	  row.price = price;
	});
}