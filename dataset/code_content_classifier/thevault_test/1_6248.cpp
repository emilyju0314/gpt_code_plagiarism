int
zero_encoder( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	  if (axis_selected == 1){
	    
	    //CreateMessage(ZERO_ENCODER);
	    newcommand.CreateZeroEncoderMsg(current_axis);
	    SendMessage(newcommand);
	     printf("Sending request to zero encoder for axis %d\n",current_axis);
	    
	  }

	return( Pt_CONTINUE );

	}