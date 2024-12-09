void reporting::blameintern(name blamer, name blamed, std::string reason, bool freeze) {
  blaming_t blaming( _self, _self.value );
	blaming.emplace( _self, [&]( auto& row ) { 
	  row.key = blaming.available_primary_key(); 
	  row.blamer = blamer;  
	  row.blamed = blamed; 
	  row.reason = reason; 
	  row.freeze = freeze; 
	  row.voteable = 1; 
	  row.confirmations = 0; 
	  row.votes = 0; 
	});
}