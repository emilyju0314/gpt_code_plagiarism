bool ViewManager::switchToLayout(int n) {
	if(n < 0 || n >= (int)names.size())
		return false;

	// Update the active layout if needed
	if(activeLayoutIndex != n) {
		activeLayoutIndex = n;
		invalidate = true;

		updateWindowTitle();

		// update tab view
		if(tabView != NULL)
			tabView->setSelectedTab(activeLayoutIndex);
	}
	return true;
}