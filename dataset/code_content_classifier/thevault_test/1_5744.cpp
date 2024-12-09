void UtilityDebugAddress(void* Pointer)
{
	const void * address = static_cast<const void*>(Pointer);
	std::stringstream ss;
	ss << address;
	std::string name = ss.str();
	FString string(name.c_str());

	UE_LOG(LeapPluginLog, Warning, TEXT("Address: %s"), *string);
}