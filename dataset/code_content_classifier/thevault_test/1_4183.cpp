void bte::propagate() {

	// Top-down 'forward' message passing
	forward();

	if (m_task == Task::PR) {
		return; // stop here to compute the log partition function
	}

	// Bottom-up 'backward' message passing
	backward();

	// Update beliefs/marginals
	update();
}