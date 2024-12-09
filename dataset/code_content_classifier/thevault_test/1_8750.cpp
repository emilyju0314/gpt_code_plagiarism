ACTION reporting::transfer(name from, name to, uint64_t amount) {
	require_auth( from );
	user_t users( _self, _self.value ); 
	auto it_from = users.find(from.value); 
	auto it_to = users.find(to.value);
	
	check( !(it_from == users.end()), "The sending account does not exist. Please enrol.");
	check( !(it_to == users.end()), "The receiving account does not exist. Please enrol.");
  check( !(it_from->frozen) , "The sending account is frozen." );
  check( !(it_to->frozen) , "The receiving account is frozen." );
	check( it_from->balance - amount < it_from->balance , "IntegerOverflow (sender), not enough balance.");
	check( it_to->balance + amount > it_to->balance , "IntegerOverflow (receiver).");
	check( it_from->balance - amount >= 0 , "Sender has not enough token.");
	check( !(it_from == it_to), "You have to send the token to another user.");

	users.modify(it_from, _self, [&]( auto& row ) { row.balance = row.balance - amount; });
	users.modify(it_to, _self, [&]( auto& row ) { row.balance = row.balance + amount; });
}