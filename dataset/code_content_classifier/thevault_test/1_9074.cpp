void ViewManager::updateWindowTitle() {
	// Make a title with format: "FollowMe - Layout name (Layout Position/Layout Count)"
	char title[256];
	sprintf(title, "FollowMe - %s (%d/%d)", getActiveLayoutName().c_str(), activeLayoutIndex+1, (int)names.size());	
	// Commit title
	SDL_WM_SetCaption(title, NULL);
}