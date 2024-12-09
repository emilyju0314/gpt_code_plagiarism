int c1::get_resources(){
	if(resource) return 0;  //resource in use
	
	else{
		resource =1;
		return 1;  //resource allocated
	}
}