int
Trend1AxisChange( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{
	  PtArg_t args[1];
	  unsigned short *newaxis;
	  
	  // index is Pt_ARG_CBOX_SEL_ITEM
	  /* eliminate 'unreferenced' warnings */
	  widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	  
	  PtSetArg( &args[0], Pt_ARG_CBOX_SEL_ITEM, &newaxis, 0 );
	  PtGetResources(ABW_AxisSelector1, 1, args);
	  current_axis[0] = *newaxis - 1;
	  printf("Trend 1 current axis = %d\n",current_axis[0]);
	  
	return( Pt_CONTINUE );

	}