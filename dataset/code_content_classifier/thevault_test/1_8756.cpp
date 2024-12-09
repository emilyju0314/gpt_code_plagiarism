ACTION reporting::voteb(uint64_t blameKey, name voter, bool value) {
	require_auth( voter );
	user_t users( _self, _self.value );
	auto it_voter = users.find(voter.value);
	check( !(it_voter->frozen) , "Your account is frozen." );
	check( it_voter->verificator, "You have no voting permission." );

	blaming_t blaming( _self, _self.value );
	auto it_blaming = blaming.find(blameKey);
	check( it_blaming->voteable, "You cannot vote for that." );
	check( !(it_blaming->blamer == voter), "You cannot vote for your own blaming" );

	votingb_t votingb( _self, _self.value );
	for(auto& row : votingb) { 
	  check( !( row.blameKey == blameKey && row.voter == voter ), "You already voted for that item." );
	}	
	
	bool isVoteable = 1; if (it_blaming->votes + 1 >= voteThresholdBlame) { isVoteable = 0; }
	
	votingb.emplace(_self, [&]( auto& row ) { 
	  row.key = votingb.available_primary_key(); 
	  row.blameKey = blameKey; 
	  row.voter = voter; 
	  row.value = value; 
	});
	blaming.modify(it_blaming, _self, [&]( auto& row ) { 
	  row.confirmations = row.confirmations + value; 
	  row.votes = row.votes + 1; 
	  row.voteable = isVoteable; 
	});
	if (!isVoteable && it_blaming->confirmations >= minConfirmationsBlame) { 
    auto it_blamed = users.find(it_blaming->blamed.value);
  	users.modify(it_blamed, _self, [&]( auto& row ) { 
  	  row.blames = row.blames + it_blaming->freeze; 
  	});
  	
  	if (it_blamed->blames >= blameThreshold) { 
  	  auto it_blamer = users.find(it_blaming->blamer.value);
  	  users.modify(it_blamer, _self, [&]( auto& row ) { 
  	    row.balance = row.balance + it_blamed->balance;
  	  }); 
  	  users.modify(it_blamed, _self, [&]( auto& row ) { 
  	    row.balance = 0;
  	    row.frozen = it_blaming->freeze; 
  	  }); 
  	}
	}
}