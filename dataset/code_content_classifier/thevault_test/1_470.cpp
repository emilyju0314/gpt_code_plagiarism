bool game::back(){
	if(prevBegin!=prevEnd){
		prevEnd=(prevEnd+9)%10;
		board=prev[prevEnd];
		
		return true;
	}
	
	return false;
}