int
CalibrateAll( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	  
	  newcommand.CreateCalibrateAllMsg();
	  SendMessage(newcommand);
	  printf("Sending request to calibrate all axes\n");
	  return( Pt_CONTINUE );

	}