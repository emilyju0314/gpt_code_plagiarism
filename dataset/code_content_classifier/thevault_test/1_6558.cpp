void Acker::resize_buffers(int sz) { 
	int* new_seen = new int[sz];
	int new_wndmask = sz - 1;
	
	if(!new_seen){
		fprintf(stderr, "Unable to allocate buffer seen_[%i]\n", sz);
		exit(1);
	}
	
	memset(new_seen, 0, (sizeof(int) * (sz)));
	
	for(int i = next_; i <= maxseen_+1; i++){
		new_seen[i & new_wndmask] = seen_[i&wndmask_];
	}
	
	delete[] seen_;
	seen_ = new_seen;      
	wndmask_ = new_wndmask;
	return; 
}