LCU::League::Class::Client::BasicSystemInfo LCU::League::Client::UX::GetSystemInfo(Session* session)
{
	// Parse response
	rapidjson::Document responseNative;
	responseNative.Parse(LCU::Network::HTTP::Get(session, "/riotclient/system-info/v1/basic-info").c_str());
	LCU::SerializedValue responseLayered(responseNative);

	// Turn response to object
	LCU::League::Class::Client::BasicSystemInfo object;
	object.init(responseLayered);

	return object;
}