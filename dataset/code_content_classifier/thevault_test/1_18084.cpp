void find_cut_list(vector< pair<int,int> > el,list<int> sa,list<int> sb,vector< pair<int,int> >& cl){
	cl.clear();
	for (int i=0; i < el.size() ; i++) {
		int ele1 = el[i].first;
		int ele2 = el[i].second;
		if(!((find_in_list(ele1,sa) && find_in_list(ele2,sa)) || (find_in_list(ele1,sb) && find_in_list(ele2,sb)))) {
			for(int i=0;i<el.size();i++){
				if((el[i].first== ele1 && el[i].second==ele2 )|| (el[i].first==ele2 && el[i].second==ele1)){
					cl.push_back(make_pair(ele1,ele2));
				}
			}
		}
	}
}