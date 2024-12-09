ACTION reporting::apply(uint64_t itemKey, name applicant) {
  require_auth( applicant );
	user_t users( _self, _self.value );
	auto it_applicant = users.find(applicant.value);
	check( !(it_applicant->frozen) , "Your account is frozen." );
	check( it_applicant->verificator, "You have no voting permission." );
	
	item_t item( _self, _self.value );
	auto it_item = item.find(itemKey);
	check( !(it_item == item.end()), "No such item on the blockchain.");
	check( it_item->appliable, "Item is closed for applications.");
	
	application_t application( _self, _self.value );
	for(auto& row : application) { 
	  check( !( row.itemKey == itemKey && row.applicant == applicant ), "You already applied for that item." ); 
	}
  
  application.emplace(_self, [&]( auto& row ) { 
	  row.key = application.available_primary_key(); 
	  row.itemKey = itemKey; 
	  row.applicant = applicant; 
	  row.active = 0;
	  row.timestamp = eosio::current_time_point(); 
	});
	item.modify(it_item, _self, [&]( auto& row ) { 
	  row.applications = row.applications + 1;
	});
	
	//last application, disable this action, enable set voters
	if (it_item->applications >= applicationThreshold) {
	  item.modify(it_item, _self, [&]( auto& row ) { 
  	  row.setvoters = 1;
  	  row.appliable = 0;
  	});
	}
}