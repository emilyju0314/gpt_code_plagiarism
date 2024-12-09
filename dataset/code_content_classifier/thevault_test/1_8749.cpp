ACTION reporting::vote(uint64_t itemKey, name voter, uint64_t overall, uint64_t description, uint64_t service, uint64_t quality) {
	require_auth( voter );
	user_t users( _self, _self.value );
	auto it_voter = users.find(voter.value);
	check( !(it_voter->frozen) , "Your account is frozen." );
	check( it_voter->verificator, "You have no voting permission." );

	item_t item( _self, _self.value );
	auto it_item = item.find(itemKey);
	check( it_item->voteable, "You cannot vote for that." );
	check( !(it_item->reporter == voter), "You cannot vote for your own item." );
	check( !(it_item->appliable), "Applications are still open." );
	check( !(it_item->setvoters), "Voters are not determined." );

	voting_t voting( _self, _self.value );
	for(auto& row : voting) { 
	  check( !( row.itemKey == itemKey && row.voter == voter ), "You already voted for that item." ); 
	}
	
	bool activeVoter = 0;
	application_t application( _self, _self.value );
	for(auto& row : application) { 
	  if(row.itemKey == itemKey && row.applicant == voter && row.active == 1) {
	    activeVoter = 1;
	    break;
	  }
	}
	check(activeVoter, "You are no selected voter.");
	
	check((overall < 100 && description < 100 && service < 100 && quality < 100), "Only 2 digits per merit allowed.");
	uint64_t merit = overall * 1000000000 + description * 1000000 + service * 1000 + quality;
	
	bool voteConfirms = 1; if(overall < 1) { voteConfirms = 0; }
	bool isVoteable = 1; if (it_item->votes + 1 >= voteThreshold) { isVoteable = 0; }
	uint64_t reward_voter = it_item->reward / ( voteThreshold - it_item->votes );
	auto it_reporter = users.find(it_item->reporter.value);	
	
	users.modify(it_reporter, _self, [&]( auto& row ) { 
	  row.statusR = row.statusR + voteConfirms; 
	});
	users.modify(it_voter, _self, [&]( auto& row ) { 
	  row.statusV = row.statusV + 1; 
	  row.balance = row.balance + reward_voter;
	});
	voting.emplace(_self, [&]( auto& row ) { 
	  row.key = voting.available_primary_key(); 
	  row.itemKey = itemKey; 
	  row.voter = voter; 
	  row.value = merit; 
	});
	item.modify(it_item, _self, [&]( auto& row ) { 
	  row.confirmations = row.confirmations + voteConfirms; 
	  row.votes = row.votes + 1; 
	  row.rating = row.rating + merit; 
	  row.voteable = isVoteable; 
	  row.reward = row.reward - reward_voter;
	});
	
	if (!isVoteable && it_item->reward > 0) {
	  //transfer back leftovers of reward
	  users.modify(it_reporter, _self, [&]( auto& row ) { 
	    row.balance = row.balance + it_item->reward; 
	  });
	  item.modify(it_item, _self, [&]( auto& row ) { 
  	  row.reward = 0;
	  });
	}
	if (!isVoteable && it_item->confirmations < minConfirmations) { 
	  //item has no sufficient quality
	  item.modify(it_item, _self, [&]( auto& row ) { 
	    row.rating = 0; 
	  }); 
	}
	//appoint as verificator if enough status points are earned
	if(it_reporter->statusR >= statusThreshold) { 
	  reporting::appoint( it_reporter->user); 
	}
}