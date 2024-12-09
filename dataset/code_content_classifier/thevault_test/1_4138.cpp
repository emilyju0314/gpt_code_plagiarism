void LMsInAndOrGraphs::generateLocalLMs(Model* htn, searchNode* tnI){
	timeval tp;
	gettimeofday(&tp, NULL);
	long startT = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	set<int> initialTasks;
	set<int> done;
	vector<planStep*> todoList;
	for (int i = 0; i < tnI->numPrimitive; i++)
		todoList.push_back(tnI->unconstraintPrimitive[i]);
	for (int i = 0; i < tnI->numAbstract; i++)
		todoList.push_back(tnI->unconstraintAbstract[i]);
	while (!todoList.empty()) {
		planStep* ps = todoList.back();
		todoList.pop_back();
		done.insert(ps->id);
		initialTasks.insert(ps->task);
		for (int i = 0; i < ps->numSuccessors; i++) {
			planStep* succ = ps->successorList[i];
			bool included = done.find(succ->id) != done.end();
			if (!included)
				todoList.push_back(succ);
		}
	}

	set<int>* lms = new set<int>();
	set<int>* collect = new set<int>();
	for (set<int>::iterator it = initialTasks.begin(); it != initialTasks.end(); ++it) {
		int task = *it;
		set<int>* newLMs = genLocalLMs(htn, task);
		for (set<int>::iterator it2 = newLMs->begin(); it2 != newLMs->end(); ++it2) {
			collect->insert(*it2);
			lms->insert(*it2);
		}
		delete newLMs;
	}
	while(!collect->empty()) {
		set<int>* lastRound = collect;
		collect = new set<int>();
		for (set<int>::iterator it = lastRound->begin(); it != lastRound->end(); ++it) {
			set<int>* newLMs = genLocalLMs(htn, *it);
			for (set<int>::iterator it2 = newLMs->begin(); it2 != newLMs->end(); ++it2) {
				int lm = *it2;
				if(lms->find(lm) == lms->end()){
					collect->insert(lm);
					lms->insert(lm);
				}
			}
		}
		delete lastRound;
	}

	tlm->clear();
	flm->clear();
	mlm->clear();

	for (int lm : *lms) {
		tlm->insert(lm);
	}

	gettimeofday(&tp, NULL);
	long endT = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	cout << "- time for LM extraction (ms) : " << (endT - startT) << endl;
}