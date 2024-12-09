std::vector<std::string> Neighbour ( std::vector<std::string> current_state, std::mt19937 & generator, std::uniform_int_distribution<int> & rand_int )
{
	std::vector<std::string> neighbour = current_state;
	int r1, r2;
	r1 = rand_int(generator);
	do 
	{ 
		r2 = rand_int(generator); 
	}
	while ( r2 == r1 );
	
	//swap
	std::swap(neighbour[r1],neighbour[r2]);
	
	return neighbour;
}