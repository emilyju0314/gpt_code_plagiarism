TSharedPtr< class IInputDevice > F3DRudderPlugin::CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	UE_LOG(_3dRudderPlugin, Log, TEXT("Create Input Device"));

	m_3DRudderDevice = MakeShareable(new F3DRudderDevice(InMessageHandler));	

	return m_3DRudderDevice;
}