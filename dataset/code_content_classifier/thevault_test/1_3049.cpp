YabInterface::YabInterface(int argc, char **argv, const char* signature)
	:BApplication(signature)
{
	BPath AppDirectory;

	// app directory
	app_info appinfo;

	if( GetAppInfo( &appinfo) == B_OK)
	{
		BEntry ApplicationEntry( &appinfo.ref);
		BEntry ApplicationDirectoryEntry;

		if( ApplicationEntry.GetParent( &ApplicationDirectoryEntry) == B_OK)
		{
			if( AppDirectory.SetTo( &ApplicationDirectoryEntry) == B_OK)
			{
				strcpy(ApplicationDirectory, AppDirectory.Path());
				// ApplicationDirectory.SetTo(AppDirectory.Path());
			}
		}
	}

	localMessage = "";

	BList *myData = new BList(3);
	myData->AddItem((void*)(addr_t)argc);
	myData->AddItem((void*)argv);
	myData->AddItem((void*)this);
	myThread = spawn_thread(interpreter,"YabInterpreter",B_NORMAL_PRIORITY,(void*)myData);
	if(myThread < B_OK)
	{
		printf("Can not start thread. Out of memory or maximum thread amount reached.\n");
		printf("Exiting now \n\n");
		exit(1);
	}
	
	if(resume_thread(myThread) < B_OK)
	{
		printf("Error while starting interpreter!\n");
		printf("Exiting now \n\n");
		exit(1);
	}

	viewList = new YabList();
	yabbitmaps = new BList();
	yabcanvas = new BList();
	drawStroking = false;
	yabPattern = B_SOLID_HIGH;
	yabAlpha = 255;
	errorCode = 0;
	Roster = NULL;
	currentLineNumber = -1;
	exiting = false;
	
	for(int i=0; i<63; i++)
		mousemessagebuffer[i] = ' ';
	mousemessagebuffer[63] = '\0';

	myProps = new BPropertyInfo(prop_list);
	currentLib = "";
	lastMouseMsg = "";
}