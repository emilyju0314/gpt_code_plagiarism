void F3DRudderPlugin::ShutdownModule()
{
	m_3DRudderDevice->~F3DRudderDevice();

	UE_LOG(_3dRudderPlugin, Log, TEXT("Shutdown Module"));
}