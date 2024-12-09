cort_tcp_connection_waiter* cort_tcp_ctrler::lock_waiter(){
	if(!this->connection_waiter){
		if(this->keep_alive_ms > 0){
			this->connection_waiter = get_keep_alive_connection_client(this->ip_v4, this->port_v4, this->type_key);
		}
		if(!this->connection_waiter){
			this->connection_waiter.init<cort_tcp_connection_waiter_client>();
		}
	}
	cort_tcp_connection_waiter* result = this->connection_waiter.get_ptr();
	result->set_parent(this);
	return result;
}