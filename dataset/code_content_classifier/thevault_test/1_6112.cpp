int
MEIDreset( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

	/* eliminate 'unreferenced' warnings */
	  widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	  //CreateMessage(MEID_RESET);
	  newcommand.CreateMEIDResetMsg();
	  SendMessage(newcommand);
	  printf("Sending request to reset MEID\n");
	  
	  
	  return( Pt_CONTINUE );

	}