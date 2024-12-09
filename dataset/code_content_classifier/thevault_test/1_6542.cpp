int WebTrafPool::find_server(int sid) {
	int n = 0;
	while (server_[n].get_nid() != sid && n < nServer_) {
		n++;
	}
	
	return(n);
}