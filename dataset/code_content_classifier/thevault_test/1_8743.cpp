ACTION reporting::report(name reporter, checksum256 hash, uint64_t parentLink, bool isIncident, uint64_t price, uint64_t reward) {
	require_auth( reporter );
	user_t users( _self, _self.value );
	auto it_reporter = users.find(reporter.value);
	check( !(it_reporter == users.end()), "No such user on the blockchain.");
	check( !(it_reporter->frozen), "This user is frozen.");
	check( (reward * voteThreshold <= it_reporter->balance), "You don't own enough token to pay for the reward.");
	
	users.modify(it_reporter, _self, [&]( auto& row ) { 
	  row.balance = row.balance - reward * voteThreshold; 
	});

	item_t item( _self, _self.value );
	for(auto& row : item) { 
	  check( !(row.hash == hash), "That item was already uploaded." ); 
	}
	item.emplace(_self, [&]( auto& row ) { 
	  row.key = item.available_primary_key(); 
	  row.parentLink = parentLink; 
	  row.reporter = reporter; 
	  row.hash = hash; 
	  row.incident = isIncident; 
	  row.voteable = 0;  
	  row.appliable = 1;
	  row.setvoters = 0;
	  row.approval = 0;
	  row.applications = 0;
	  row.confirmations = 0;  
	  row.votes = 0;  
	  row.rating = 0; 
	  row.price = price;
	  row.reward = reward * voteThreshold;
	});
}