ACTION reporting::selectvoter(name reporter, uint64_t itemKey, uint64_t nonce) {
  require_auth( reporter );
	user_t users( _self, _self.value );
	auto it_reporter = users.find(reporter.value);
	check( !(it_reporter->frozen) , "Your account is frozen." );
  
  item_t item( _self, _self.value );
	auto it_item = item.find(itemKey);
	check( !(it_item == item.end()), "No such item on the blockchain.");
	check( it_item->setvoters, "Application or Voting is open.");
	check( it_item->reporter == reporter, "This action has to be called by the reporter self.");
	
	//get applications for item
	uint64_t application_nums[applicationThreshold];
	uint64_t random_nums[applicationThreshold];
	uint64_t counter = 0;
	application_t application( _self, _self.value );
	for(auto& row : application) { 
	  if( row.itemKey == itemKey ) { 
	    eosio::microseconds difference = eosio::current_time_point() - row.timestamp;
	    random_nums[counter] = reporting::random(difference.count(), row.applicant.value, nonce);
	    application_nums[counter] = row.key;
	    counter = counter + 1;
	  }
	}
	
	//sort
	bool done = 0;
	while(!done) {
	  done = 1;
  	for(uint64_t i = 1; i < applicationThreshold; i++ ) {
  	  if (random_nums[i - 1] > random_nums[i]) {
  	    uint64_t swap1 = random_nums[i];
  	    random_nums[i] = random_nums[i - 1];
  	    random_nums[i - 1] = swap1;
  	    
  	    uint64_t swap2 = application_nums[i];
  	    application_nums[i] = application_nums[i - 1];
  	    application_nums[i - 1] = swap2;
  	    
  	    done = 0;
  	  }
  	}
	}
	//choose lowest random numbers and set as voters
	for(uint64_t i = 0; i < applicationThreshold; i++ ) {
	  print(random_nums[i], " ");
	  print(application_nums[i], " ");
	  if(i < voteThreshold) {
	    auto it_application = application.find(application_nums[i]);
  	  application.modify(it_application, _self, [&]( auto& row ) { 
    	  row.active = 1;
    	});
    	
    	//set order for consistency
    	order_t order( _self, _self.value );
    	order.emplace(_self, [&]( auto& row ) { 
    	  row.key = order.available_primary_key();  
    	  row.itemKey = itemKey;
    	  row.seller = reporter;
    	  row.buyer = it_application->applicant; 
    	  row.sent = 1;
    	  row.received = 0; 
    	});
	  }
	}
	
	//set status of item
	item.modify(it_item, _self, [&]( auto& row ) { 
  	row.setvoters = 0;
  	row.voteable = 1;
  });
	
}