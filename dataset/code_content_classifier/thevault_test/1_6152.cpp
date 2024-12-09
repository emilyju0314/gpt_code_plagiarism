int
TimerActivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

	  PtArg_t args[1];
	  int scaled_position_array[N_VIEWERS];
	  int actual_position_array[N_VIEWERS];
	  int position_value[1];
	  int val;
	  
	  /* eliminate 'unreferenced' warnings */
	  widget = widget, apinfo = apinfo, cbinfo = cbinfo;


	  float temp;
	  
	  K4JointPos pos = ReadInput();
	    for (int i = 0; i < N_VIEWERS; i++){
	      //printf("set pos array [%d] to pos(%d)\n",i,current_axis[i]+1);
	      actual_position_array[i] = pos.positions[current_axis[i]];
	      temp = pos.positions[current_axis[i]] / SCALE_FACTOR;
	      scaled_position_array[i] = temp;
	    }
	    
	    //trend 1
	    position_value[0] = scaled_position_array[0];
	    
	    PtSetArg(&args[0], Rt_ARG_TREND_DATA, position_value, 1);
	    PtSetResources(ABW_Trend1, 1, args);
	    
	    
	    val = actual_position_array[0];
	    PtSetArg(&args[0], Pt_ARG_NUMERIC_VALUE, val, 0);
	    PtSetResources(ABW_TrendValue1, 1, args);
	    
	    //trend2
	  position_value[0] = scaled_position_array[1];
	  
	  PtSetArg(&args[0], Rt_ARG_TREND_DATA, position_value, 1);
	  PtSetResources(ABW_Trend2, 1, args);
	  
	  
	  val = actual_position_array[1];
	  PtSetArg(&args[0], Pt_ARG_NUMERIC_VALUE, val, 0);
	  PtSetResources(ABW_TrendValue2, 1, args);

	  
	    //trend 3
	    position_value[0] = scaled_position_array[2];
	  
	    PtSetArg(&args[0], Rt_ARG_TREND_DATA, position_value, 1);
	    PtSetResources(ABW_Trend3, 1, args);
	  
	  
	    //val = position_value[0];
	    val = actual_position_array[2];
	  PtSetArg(&args[0], Pt_ARG_NUMERIC_VALUE, val, 0);
	    PtSetResources(ABW_TrendValue3, 1, args);
	  
	    //trend4
	  position_value[0] = scaled_position_array[3];
	  
	  PtSetArg(&args[0], Rt_ARG_TREND_DATA, position_value, 1);
	  PtSetResources(ABW_Trend4, 1, args);
	  
	  
	  val = actual_position_array[3];
	  PtSetArg(&args[0], Pt_ARG_NUMERIC_VALUE, val, 0);
	  PtSetResources(ABW_TrendValue4, 1, args);

	  
	  
	  //trend5 (all)
	  
	  PtSetArg(&args[0], Rt_ARG_TREND_DATA, scaled_position_array, 4);
	  PtSetResources(ABW_Trend5, 1, args);
	  
       
	  
	  
	  return( Pt_CONTINUE );

	}