int
axischange( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{
	  //if (connected == 1){
	    PtArg_t args[1];
	    unsigned short *newaxis;
	    
	    // index is Pt_ARG_CBOX_SEL_ITEM
	    /* eliminate 'unreferenced' warnings */
	    widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	    
	    PtSetArg( &args[0], Pt_ARG_CBOX_SEL_ITEM, &newaxis, 0 );
	    PtGetResources(ABW_AxisSelector, 1, args);
	    current_axis = (short)(*newaxis - 1);
	    axis_selected = 1;
	    return( Pt_CONTINUE );

	}