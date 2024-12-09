void CMaterialSystem::HandleDeviceLost()
{
	if ( IsGameConsole() )
		return;

	g_pShaderAPI->HandleDeviceLost();
}