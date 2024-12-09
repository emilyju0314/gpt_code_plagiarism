void CShaderAPIDx8::DXSupportLevelChanged( int nDXLevel )
{
	LOCK_SHADERAPI();
	if ( IsPC() )
	{
		OverrideCaps( nDXLevel );
	}
	else
	{
		Assert( 0 );
	}
}