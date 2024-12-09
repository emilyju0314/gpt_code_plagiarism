void CShaderAPIDx8::OverrideCaps( int nForcedDXLevel )
{
	// Just use the actual caps if we can't use what was requested or if the default is requested
	if ( nForcedDXLevel <= 0 ) 
	{
		nForcedDXLevel = g_pHardwareConfig->ActualCaps().m_nDXSupportLevel;
	}
	nForcedDXLevel = g_pShaderDeviceMgr->GetClosestActualDXLevel( nForcedDXLevel );

	g_pHardwareConfig->SetupHardwareCaps( nForcedDXLevel, g_pHardwareConfig->ActualCaps() );
}