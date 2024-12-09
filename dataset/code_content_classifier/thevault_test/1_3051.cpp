void YabInterface::OpenWindow(const BRect frame, const char* id, const char* title)
{
	YabWindow* w = new YabWindow(frame,title,id, B_TITLED_WINDOW_LOOK, B_NORMAL_WINDOW_FEEL, B_ASYNCHRONOUS_CONTROLS);
	YabView* myView = new YabView(w->Bounds(), id, B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_NAVIGABLE_JUMP);
	w->Lock();
		w->AddChild(myView);

		viewList->AddView(id, myView, TYPE_YABVIEW);
		// viewList->PrintOut();

		// w->Minimize();
		w->SetSizeLimits(10,3000,10,3000);
		w->Show();
	w->Unlock();
	w->layout = -1;
}