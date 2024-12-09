bool find_in_list(int val,list<int>& set){
	if(find(set.begin(),set.end(),val) == set.end()){
		return false;
	}else{
		return true;
	}
}