short int game::ruleStringToInt(string s){
	short int	x;
	
	x = 0;
	for(auto i:s){
		if(i<'0' || i>='9')
			continue;
			
		i-='0';
		x |= 1<<i;
	}
	
	return x;
}