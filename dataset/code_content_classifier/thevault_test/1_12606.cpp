int qsimproxy_core_t :: run(int count)
{
//cout << "run() called, count= " << count << endl;
    Qsim::QueueItem item(0);

    int cnt = 0;
    while(cnt < count) {
        if(m_shm->is_empty()) {
	    cout << "buffer is empty\n";
	    usleep(50000); //0.05s
	    break;
	}
	item = m_shm->read();
	//cout << "run() got an item\n";
	//item.print();
	cnt++;
	m_q.push_back(item);
    }

    return cnt;
}