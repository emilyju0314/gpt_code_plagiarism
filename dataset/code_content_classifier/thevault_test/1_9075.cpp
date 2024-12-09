void ViewManager::drawActiveLayout(SDL_Surface * screen, bool useLocalScreenUpdate) {
	if(invalidate) {
		// Fill background with white
		SDL_FillRect(screen, NULL, 0xffffffff);
		// Draw tle layout
		getActiveLayout().draw(screen, true, false);
		// Draw the tab view
		if(tabView != NULL)
			tabView->draw(screen, true, false);
		// Update the whole screen
		SDL_Flip(screen);
		invalidate = false;
	}
	else {
		// Draw the layout
		getActiveLayout().draw(screen, false, useLocalScreenUpdate);
		// Draw the tab view
		if(tabView != NULL)
			tabView->draw(screen, false, useLocalScreenUpdate);
		// Update the whole screen if required
		if(!useLocalScreenUpdate)
			SDL_Flip(screen);
	}
}