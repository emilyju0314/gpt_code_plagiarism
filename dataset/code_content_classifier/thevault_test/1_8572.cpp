void containers()
{
	// Every container in c++ is move aware in in==one way to another

	std::vector<foo> v;
	auto v_copy = v;
	auto v_move = std::move(v);
	
	// Moves temporary inside the vector
	v.push_back(foo{}); // no copies peformed

	foo f;
	// Copies 'f' inside vector
	v.push_back(f);


	// Moves 'f' inside vector
	v.push_back(std::move(f));

	// Ref: https://en.cppreference.com/w/cpp/container/vector/push_back
	// void push_back( T&& value );

}