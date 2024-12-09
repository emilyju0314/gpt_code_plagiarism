void swap_nodes(list<int>& l1,list<int>& l2,int n1,int n2){
	list<int>::iterator vliter;
	for(vliter=l1.begin();vliter!=l1.end();++vliter){
		if(*vliter == n1) {
			*vliter = n2;
		}
	}		
	for(vliter=l2.begin();vliter!=l2.end();++vliter){
		if(*vliter == n2) {
			*vliter = n1;
		}
	}		
}