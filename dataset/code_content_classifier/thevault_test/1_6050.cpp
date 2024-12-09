int YAPOCVirtualControl::CalibrateEach(int vnumber){
   if (axismap[vnumber][AXISTYPE] == MEITYPE){
     if (DEBUG) printf("Will calibrate axis %d \n",axismap[vnumber][AXISNUMBER]);

     /*
     if (MEIhead.Calibrate(axismap[vnumber][AXISNUMBER]) == 0){
       double min, max;
       MEIhead.GetLimits (axismap[vnumber][AXISNUMBER], &min, &max);
       MEIhead.SetLimits (axismap[vnumber][AXISNUMBER], min + 1000.0, max - 1000.0);
       return 0;
       
     }
     else
       return -1;
      */
     return 0;
   }
   else if (axismap[vnumber][AXISTYPE] == PICTYPE){
     
     //nt calibrate_axis(byte axis, int verbose);
     //nt calibrate_multi(int len,int *axes, int verbose);
     int actnumber = axismap[vnumber][AXISNUMBER];
    /*
     if (PICheads[pics_axes[actnumber]].calibrate_axis(
						       address_axes[actnumber],0))
       return 0;
     else
       return -1;
    */ 
     
     return 0;
   }
   else
     return -1;
   
 }