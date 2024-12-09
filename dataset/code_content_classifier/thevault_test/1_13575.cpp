int Energy( std::vector<std::string> state)
{
	int count = 0;
	
	for(int i=0; i<N-1; i++)
	{
		for(int j=0; j<4;  j++)
		{
			if( state[i][j] == state[i+1][j] ) count++;
			if(i != N-2) if( state[i][j]  == state[i+2][j] ) count++;
			//if(i != N-2) if( state[i][j+1] == state[i+2][j] ) count++;
		}
	}
	
	return count;
}