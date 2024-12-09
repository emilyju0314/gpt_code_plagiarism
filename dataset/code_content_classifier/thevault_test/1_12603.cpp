bool simple_cache::insert_mshr_entry (Cache_req *request)
{
    assert(request->op_type == OpMemLd);

    bool found = false;
    list<mshr_entry *>::iterator it;
    for (it = m_mshr.begin(); it != m_mshr.end(); it++)
    {
	if (my_table->get_line_addr ((*it)->creq->addr) == my_table->get_line_addr (request->addr)) {
	    found = true;
	    break;
        }
    }

    m_mshr.push_back (new mshr_entry(request));
    return found;
}