int
Trend4MaxChange( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

{
  
            PtArg_t args[1];
            short int tmax;
            PtNumericIntegerCallback_t *cb;
  
            /* eliminate 'unreferenced' warnings */
            widget = widget, apinfo = apinfo, cbinfo = cbinfo;
  
            cb = (PtNumericIntegerCallback *)cbinfo->cbdata;
            tmax = cb->numeric_value;
  
            // printf("max set to %d\n", tmax);
  
            PtSetArg(&args[0], Rt_ARG_TREND_MAX, tmax, 1);
            PtSetResources(ABW_Trend4, 1, args);
            return( Pt_CONTINUE );
  
}