void LLP_cache :: tick()
{
    while(m_lls_requests.size() > 0) {
        Coh_msg* req = m_lls_requests.front();
	m_lls_requests.pop_front();
	process_peer_and_manager_request(req);
    }

    L1_cache :: tick();

}