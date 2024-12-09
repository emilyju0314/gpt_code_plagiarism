ACTION reporting::enrol(name user, std::string publicKey) {
  require_auth(user);
  user_t users( _self, _self.value );
	auto it = users.find(user.value);
	check(it == users.end(), "User already on the blockchain.");
	users.emplace(_self, [&]( auto& row ) { 
	  row.user = user; 
	  row.balance = 0; 
	  row.statusR = 0; 
	  row.statusV = 0; 
	  row.blames = 0; 
	  row.verificator = 0; 
	  row.frozen = 0; 
	  row.publicKey = publicKey;
	});
}