int
ResetPIC( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	//CreateMessage(PIC_RESET);
	newcommand.CreatePICResetMsg();
	  SendMessage(newcommand);
        printf("Sending request to reset PIC\n");
	return( Pt_CONTINUE );

	}