int
Trend4MinChange( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

{
            PtArg_t args[1];
            short int tmin;
            PtNumericIntegerCallback_t *cb;
  
            /* eliminate 'unreferenced' warnings */
            widget = widget, apinfo = apinfo, cbinfo = cbinfo;
  
            cb = (PtNumericIntegerCallback *)cbinfo->cbdata;
            tmin = cb->numeric_value;
  
            // printf("min set to %d\n", tmin);
  
            PtSetArg(&args[0], Rt_ARG_TREND_MIN, tmin, 1);
            PtSetResources(ABW_Trend4, 1, args);
            return( Pt_CONTINUE );
  
}