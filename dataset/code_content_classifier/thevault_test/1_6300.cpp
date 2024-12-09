int
Axis15Toggle( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	  int naxis = 15;
	  int stat = read_state_from_onoff(widget);
	  if (stat == 0){
	      if (statusbits[naxis] != OFF){
		    //off
		    statusbits[naxis] = OFF;
		    write_text_to_widget(widget,OFF_TEXT, Pg_BLUE);
	      }
	  }
	  else {
	      if (statusbits[naxis] == OFF){
		    //on
		    statusbits[naxis] = ON;
		    write_text_to_widget(widget,ON_TEXT,Pg_RED);
	      }
	  }
	return( Pt_CONTINUE );

	}