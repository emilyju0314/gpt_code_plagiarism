int
Realized( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	  int trend_color_array[N_VIEWERS] = {   Pg_RED,
	    Pg_BLUE,
	    Pg_YELLOW,
	            Pg_MAGENTA
	      
	   };
	  
	  
	   RtTrendAttr_t one_attr, several_attr[N_VIEWERS];
	   PtArg_t args[2];
	  
	   /* Set up the color list. */
	   PtSetArg (&args[0], Rt_ARG_TREND_COLOR_LIST, trend_color_array, N_VIEWERS);
	   PtSetResources (widget, 1, args);
	  
	   /* Map the trends to colors. */
	   for (int i = 0; i < N_VIEWERS; i++)
	      several_attr[i].map = i+1;
	      
     	   PtSetArg (&args[0], Rt_ARG_TREND_ATTRIBUTES,
		                          several_attr, 0);
	   PtSetResources (widget, 1, args);
	  
	  
	  
	  return( Pt_CONTINUE );

	}