int
axis26slider_move( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

PtSliderCallback_t *cb;
	  /* eliminate 'unreferenced' warnings */
	  widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	  cb = (PtSliderCallback_t *)cbinfo->cbdata;
	  newpositions[26] = (float)cb->position;
	  printf("Slider 26 has been moved to %f\n",newpositions[26]);

	return( Pt_CONTINUE );

	}