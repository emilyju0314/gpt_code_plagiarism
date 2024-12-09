void YabInterface::BitmapGet(BRect frame, const char* id, const char* bitmap)
{
	
	for(int i=0; i<yabbitmaps->CountItems(); i++)
	{
		BBitmap *b = (BBitmap*)yabbitmaps->ItemAt(i);
		BView *bview = b->FindView(bitmap);
	
		if(bview)
		{
			char *oldbits, *newbits;
			
			BBitmap *newbmp = new BBitmap(BRect(0,0, frame.Width()-1, frame.Height()-1), B_RGBA32, true);	//-1 Added, because correction of right and height limit		
			BView *newbview = new BView(BRect(0,0, frame.Width()-1, frame.Height()-1), id, B_FOLLOW_NONE, 0);//-1 Added, because correction of right and height limit
			
			newbmp->AddChild(newbview);
			newbits = (char*)newbmp->Bits();
			for(int i=0; i<(frame.Width()-1)*(frame.Height()-1)*4; i = i + 4)  //-1 Added, because correction of right and height limit
			{
				newbits[i] = newbits[i+1] = newbits[i+2] = 255;
				newbits[i+3] = 0;
			}
			oldbits = (char*)b->Bits();
			b->Lock();
			BRect tframe = bview->Bounds();
			b->Unlock();
			if(frame.top>tframe.bottom || frame.left>tframe.right || (frame.bottom-1)>tframe.bottom || (frame.right-1)>tframe.right || frame.top<0 || frame.left<0 || frame.right<0 || frame.bottom<0)
				ErrorGen("Out of bounds");
			for(int32 j = 0; j<frame.IntegerHeight(); j++)
				for(int32 k = 0; k<frame.IntegerWidth(); k++)
					for(int32 l = 0; l<4; l++)
						newbits[j*newbmp->BytesPerRow()+k*4+l] = oldbits[(int32)((j+frame.top)*b->BytesPerRow()+(k+frame.left)*4+l)];						
			yabbitmaps->AddItem(newbmp);
			return;
		}
	}
	for(int i=0; i<yabcanvas->CountItems(); i++)
	{
		YabBitmapView *myView = (YabBitmapView*)yabcanvas->ItemAt(i);
		
		if(!strcmp(myView->Name(), bitmap))
		{
			YabWindow *w = cast_as(myView->Window(), YabWindow);
			if(w)
			{
				w->Lock();
				BBitmap *b = myView->GetBitmap();
				char *oldbits, *newbits;
				BBitmap *newbmp = new BBitmap(BRect(0,0, frame.Width()-1, frame.Height()-1), B_RGBA32, true);//-1 Added, because correction of right and height limit
				BView *newbview = new BView(BRect(0,0, frame.Width()-1, frame.Height()-1), id, B_FOLLOW_NONE, 0);//-1 Added, because correction of right and height limit
				newbmp->AddChild(newbview);
				newbits = (char*)newbmp->Bits();
				
				for(int i=0; i<(frame.Width()-1)*(frame.Height()-1)*4; i = i + 4)  //-1 Added, because correction of right and height limit
				{
					newbits[i] = newbits[i+1] = newbits[i+2] = 255;
					newbits[i+3] = 0;
				}
				oldbits = (char*)b->Bits();
				BRect tframe = myView->Bounds();
				if(frame.top>tframe.bottom || frame.left>tframe.right || (frame.bottom-1)>tframe.bottom || (frame.right-1)>tframe.right || frame.top<0 || frame.left<0 || frame.right<0 || frame.bottom<0)
					ErrorGen("Out of bounds");
				for(int32 j = 0; j<frame.IntegerHeight(); j++)
					for(int32 k = 0; k<frame.IntegerWidth(); k++)
						for(int32 l = 0; l<4; l++)
							newbits[j*newbmp->BytesPerRow()+k*4+l] = oldbits[(int32)((j+frame.top)*b->BytesPerRow()+(k+frame.left)*4+l)];
				yabbitmaps->AddItem(newbmp);
				w->Unlock();
				return;
			}
		}
	}  
	Error(bitmap, "BITMAP or CANVAS");
}