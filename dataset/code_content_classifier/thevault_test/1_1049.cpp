F3DRudderDevice::~F3DRudderDevice() 
{
	ns3dRudder::EndSDK();
	UE_LOG(Log3dRudderDevice, Log, TEXT("Closing 3DRudderDevice"));
}