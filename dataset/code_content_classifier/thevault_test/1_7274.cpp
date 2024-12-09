void Fl::paste(Fl_Widget &receiver, int clipboard) {
    if (clipboard) {
	// see if we own the selection, if not go get it:
	fl_selection_length[1] = 0;
#ifdef USE_PASTEBOARD
	OSStatus err = noErr;
	Boolean found = false;
	CFDataRef flavorData = NULL;
	CFStringEncoding encoding = 0;

	allocatePasteboard();
	PasteboardSynchronize(myPasteboard);
	ItemCount nFlavor = 0, i, j;
	err = PasteboardGetItemCount(myPasteboard, &nFlavor);
	if (err==noErr) {
	    for (i=1; i<=nFlavor; i++) {
		PasteboardItemID itemID = 0;
		CFArrayRef flavorTypeArray = NULL;
		found = false;
		err = PasteboardGetItemIdentifier(myPasteboard, i, &itemID);
		if (err!=noErr) continue;
		err = PasteboardCopyItemFlavors(myPasteboard, itemID, &flavorTypeArray);
		if (err!=noErr) {
		  if (flavorTypeArray) {CFRelease(flavorTypeArray); flavorTypeArray = NULL;}
		  continue;
		}
		CFIndex flavorCount = CFArrayGetCount(flavorTypeArray);
		for (j = 0; j < handledFlavorsCount; j++) {
		    for (CFIndex flavorIndex=0; flavorIndex<flavorCount; flavorIndex++) {
			CFStringRef flavorType = (CFStringRef)CFArrayGetValueAtIndex(flavorTypeArray, flavorIndex);
			if (UTTypeConformsTo(flavorType, flavorNames[j])) {
			    err = PasteboardCopyItemFlavorData( myPasteboard, itemID, flavorNames[j], &flavorData );
			    if(err != noErr) continue;
			    encoding = encodings[j];
			    found = true;
			    break;
			}
		    }
		    if(found) break;
		}
		if (flavorTypeArray) {CFRelease(flavorTypeArray); flavorTypeArray = NULL;}
		if (found) break;
	    }
	    if(found) {
		CFIndex len = CFDataGetLength(flavorData);
		CFStringRef mycfs = CFStringCreateWithBytes(NULL, CFDataGetBytePtr(flavorData), len, encoding, false);
		CFRelease(flavorData);
		len = CFStringGetMaximumSizeForEncoding(CFStringGetLength(mycfs), kCFStringEncodingUTF8) + 1;
		if ( len >= fl_selection_buffer_length[1] ) {
		    fl_selection_buffer_length[1] = len;
		    delete[] fl_selection_buffer[1];
		    fl_selection_buffer[1] = new char[len];
		}
		CFStringGetCString(mycfs, fl_selection_buffer[1], len, kCFStringEncodingUTF8);
		CFRelease(mycfs);
		len = strlen(fl_selection_buffer[1]);
		fl_selection_length[1] = len;
		convert_crlf(fl_selection_buffer[1],len); // turn all \r characters into \n:
	    }
	}
#else
	ScrapRef scrap = 0;
	if (GetCurrentScrap(&scrap) == noErr && scrap != myScrap &&
	    GetScrapFlavorSize(scrap, kScrapFlavorTypeText, &len) == noErr) {
	    if ( len >= fl_selection_buffer_length[1] ) {
		fl_selection_buffer_length[1] = len + 32;
		delete[] fl_selection_buffer[1];
		fl_selection_buffer[1] = new char[len + 32];
	    }
	    fl_selection_length[1] = len; len++;
	    GetScrapFlavorData( scrap, kScrapFlavorTypeText, &len,
			       fl_selection_buffer[1] );
	    fl_selection_buffer[1][fl_selection_length[1]] = 0;
	    convert_crlf(fl_selection_buffer[1],len); 
	}
#endif
    }
    Fl::e_text = fl_selection_buffer[clipboard];
    Fl::e_length = fl_selection_length[clipboard];
    if (!Fl::e_text) Fl::e_text = (char *)"";
    receiver.handle(FL_PASTE);
}