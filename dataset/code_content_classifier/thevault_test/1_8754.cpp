ACTION reporting::blame(name blamer, name blamed, std::string reason, bool freeze) {
	require_auth( blamer );
	user_t users( _self, _self.value );
	auto it_blamer = users.find(blamer.value);
	check( !(it_blamer == users.end()) , "Please enrol first." );
	if(freeze) { check( !(it_blamer->frozen) , "Your account is frozen." ); }
	
	check(reason.length() < 128, "Less than 128 characters allowed.");
	
	auto it_blamed = users.find(blamed.value);
	check( !(it_blamed == users.end()) , "Blamed user not enrolled." );
	
	reporting::blameintern(blamer, blamed, reason, freeze);
}