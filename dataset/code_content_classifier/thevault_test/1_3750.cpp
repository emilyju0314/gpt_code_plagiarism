double CSystem::GetTimeSinceLastUse()
{
	if (m_bStaticWatchForComputerUse)
	{
		return ( Plat_MSTime() - m_StaticLastComputerUseTime ) / 1000.0f;
	}

	return 0.0f;
}