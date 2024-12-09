void reporting::appoint(name user) {
	user_t users( _self, _self.value );
	auto iterator = users.find(user.value);
	check( !(iterator == users.end()), "No such user on the blockchain.");
	check( !(iterator->frozen), "This user is frozen.");
	check( iterator->statusR >= statusThreshold, "The user did not earn enough status points to become a verificator.");
	users.modify(iterator, _self, [&]( auto& row ) { 
	  row.verificator = 1; 
	});
}