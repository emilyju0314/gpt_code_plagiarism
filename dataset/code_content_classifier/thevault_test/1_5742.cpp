void ULeapController::SetInterfaceDelegate(UObject* NewDelegate)
{
	UE_LOG(LeapPluginLog, Log, TEXT("InterfaceDelegate: %s"), *NewDelegate->GetName());

	//Use this format to support both blueprint and C++ form
	if (NewDelegate->GetClass()->ImplementsInterface(ULeapEventInterface::StaticClass()))
	{
		Private->CurrentlyUsedDelegate = NewDelegate;	//reference our delegate so we can remove it later
		ILeapMotionPlugin::Get().AddEventDelegate(Private->CurrentlyUsedDelegate);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("LeapController Warning: Delegate is NOT set, did you implement LeapEventInterface?"));
	}
}