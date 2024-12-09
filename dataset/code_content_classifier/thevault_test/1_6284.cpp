int
MoveToPos( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{


	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	  short uselimit_flag = 1;
	  newcommand.CreatePositionCommandMsg(newpositions,statusbits,uselimit_flag);
	  SendMessage(newcommand);
	  
	return( Pt_CONTINUE );

	}