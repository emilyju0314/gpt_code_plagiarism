void
thread_pool::stop(void) {
	if (!is_running()) { return; }

	m_should_stop = true;
	m_tasks_condvar.notify_all();

	for (auto& worker : m_workers) { worker.join(); }

	m_workers.clear();

	__MC_LOG(debug, "thread_pool stopped");
}