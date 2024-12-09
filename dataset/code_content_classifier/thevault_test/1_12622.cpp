void SimpleRouter :: set_port_cross_lp (int port)
{
    port_cross_lp[port] = true;
    if (!cross_lp_flag)
	cross_lp_flag = true;
    //cout<<"router: "<<node_id<<" port: "<<port<<endl;
}