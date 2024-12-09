void LoopFilter::loopFilterPic( CodingStructure& cs ) const
{
  PROFILER_SCOPE_AND_STAGE( 1, g_timeProfiler, P_DBFILTER );
  if( cs.pps->getDeblockingFilterControlPresentFlag() && cs.pps->getPPSDeblockingFilterDisabledFlag() && !cs.pps->getDeblockingFilterOverrideEnabledFlag() )
  {
    return;
  }

  const PreCalcValues& pcv = *cs.pcv;

  DTRACE_UPDATE( g_trace_ctx, ( std::make_pair( "poc", cs.picture->poc ) ) );

#if ENABLE_TRACING
  for( int y = 0; y < pcv.heightInCtus; y++ )
  {
    for( int x = 0; x < pcv.widthInCtus; x++ )
    {
      const UnitArea ctuArea( pcv.chrFormat, Area( x << pcv.maxCUWidthLog2, y << pcv.maxCUHeightLog2, pcv.maxCUWidth, pcv.maxCUWidth ) );
      DTRACE    ( g_trace_ctx, D_CRC, "CTU %d %d", ctuArea.Y().x, ctuArea.Y().y );
      DTRACE_CRC( g_trace_ctx, D_CRC, cs, cs.picture->getRecoBuf( clipArea( ctuArea, *cs.picture ) ), &ctuArea.Y() );
    }
  }
#endif

  for( unsigned y = 0; y < pcv.heightInCtus; y++ )
  {
    loopFilterPicLine( cs, MAX_NUM_CHANNEL_TYPE, y );
  }

  DTRACE_PIC_COMP(D_REC_CB_LUMA_LF,   cs, cs.getRecoBuf(), COMPONENT_Y);
  DTRACE_PIC_COMP(D_REC_CB_CHROMA_LF, cs, cs.getRecoBuf(), COMPONENT_Cb);
  DTRACE_PIC_COMP(D_REC_CB_CHROMA_LF, cs, cs.getRecoBuf(), COMPONENT_Cr);

  DTRACE    ( g_trace_ctx, D_CRC, "LoopFilter" );
  DTRACE_CRC( g_trace_ctx, D_CRC, cs, cs.getRecoBuf() );
}