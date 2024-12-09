bool check_if_edge_exists(vector<pair<int,int> >el,int v1,int v2){
	for (int i=0;i<el.size();i++){
		if((el[i].first==v1 && el[i].second == v2 )|| (el[i].first==v2 && el[i].second==v1)) {
			return true;
		}
	}
	return false;
}