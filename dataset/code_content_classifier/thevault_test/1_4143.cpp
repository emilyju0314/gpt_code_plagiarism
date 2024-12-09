uint64_t VisitedList::taskCountHash(searchNode * n){
	uint64_t lhash = 1;
    for (int i = 0; i < n->numContainedTasks; i++) {
        uint64_t numTasks = this->htn->numTasks;
        uint64_t task = n->containedTasks[i];
        uint64_t count = n->containedTaskCount[i];
        DEBUG(cout << task << " " << count << endl);
        for (unsigned int j = 0; j < count; j++) {
            unsigned int p_index = j * numTasks + task;
            unsigned int p = getPrime(p_index);
            DEBUG(cout << "p: " << p << endl);
            lhash = lhash * p;
            lhash = lhash % tenThousandthP;
        }
    }
    return lhash;
}