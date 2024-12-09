ACTION reporting::updatepk(name user, std::string publicKey) {
  require_auth(user);
  user_t users( _self, _self.value );
	auto iterator = users.find(user.value);
	check( !(iterator == users.end()), "No such user on the blockchain.");
	check( !(iterator->frozen), "This user is frozen.");
	users.modify(iterator, _self, [&]( auto& row ) { 
	  row.publicKey = publicKey;
	});
}