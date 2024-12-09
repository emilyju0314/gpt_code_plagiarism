bool JobInStack(int JobId) {
		for (int i = 0; i < jobStack.size(); i++)
		{
			if (jobStack[i]->GetId() == JobId)
				return true;
		}
		return false;
	}