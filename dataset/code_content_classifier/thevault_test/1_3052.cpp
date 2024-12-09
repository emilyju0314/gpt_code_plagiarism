void YabInterface::TextURL(double x, double y, const char* id, const char* text, const char* url, const char* view)
{
	YabView *myView = cast_as((BView*)viewList->GetView(view), YabView);
	if(myView)
	{
		YabWindow *w = cast_as(myView->Window(), YabWindow);
		if(w)
		{
			w->Lock();
			double h,b;
						
			b = be_plain_font->StringWidth(text)+1;
			h = be_plain_font->Size(); 
			
			URLView *s = new URLView(BRect(x,y,x+b,y+h+3), id, text, url); //Correction of Height +3 added,because text wasn't fully displayed. Lorglas
			s->SetHoverEnabled(true);
			if(w->layout == -1)
				s->SetResizingMode(B_FOLLOW_RIGHT|B_FOLLOW_BOTTOM);
			else
				s->SetResizingMode(w->layout);
			s->SetFlags(B_WILL_DRAW);
			myView->AddChild(s);
			w->Unlock();
		}
		else
			ErrorGen("Unable to lock window");
	}
	else
		Error(view, "VIEW");
}