bool compute_Rintanten_action_applicable(Model * htn,
		int tIndex,
		vector<pair<int,int>> & v0,
		bool * & toDelete,
		vector<vector<int>> & posInvarsPerPredicate,
		vector<vector<int>> & negInvarsPerPredicate,
		bool * & posInferredPreconditions,
		bool * & negInferredPreconditions
	){
	
	// infer additional preconditions and effects
	for (int p1 = 0; p1 < htn->numStateBits; p1++){
		posInferredPreconditions[p1] = false;
		negInferredPreconditions[p1] = false;
	}

	bool inapplicable = false;
	for (size_t preIndex = 0; !inapplicable && preIndex < htn->numPrecs[tIndex]; preIndex++){
		int pre = htn->precLists[tIndex][preIndex];
		posInferredPreconditions[pre] = true;

		// look only at the invariants that are possibly matching this precondition
		for (size_t invarListIndex = 0; invarListIndex < negInvarsPerPredicate[pre].size(); invarListIndex++){
			int invar = negInvarsPerPredicate[pre][invarListIndex];
			if (toDelete[invar]) continue;
			if (v0[invar].first < 0 && pre == -v0[invar].first-1){
				if (v0[invar].second < 0){
					negInferredPreconditions[-v0[invar].second - 1] = true;
					if (posInferredPreconditions[-v0[invar].second - 1]) {inapplicable = true; break;}
				} else {
					posInferredPreconditions[ v0[invar].second] = true;
					if (negInferredPreconditions[v0[invar].second]) {inapplicable = true; break;}
				}
			}
			if (v0[invar].second < 0 && pre == -v0[invar].second-1){
				if (v0[invar].first < 0){
					negInferredPreconditions[-v0[invar].first - 1] = true;
					if (posInferredPreconditions[-v0[invar].first - 1]) {inapplicable = true; break;}
				} else {
					posInferredPreconditions[ v0[invar].first] = true;
					if (negInferredPreconditions[v0[invar].first]) {inapplicable = true; break;}
				}
			}
		}
	}
	return !inapplicable;
}