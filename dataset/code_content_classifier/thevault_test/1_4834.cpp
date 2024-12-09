std::vector<std::string> LCU::League::Client::UX::GetCommandLineArgs(Session* session)
{
	// Parse response
	rapidjson::Document responseNative;
	responseNative.Parse(LCU::Network::HTTP::Get(session, "/riotclient/command-line-args").c_str());
	LCU::SerializedValue responseLayered(responseNative);

	// Turn response to object array
	std::vector<LCU::SerializedValue> responseArray = responseLayered.asVector();
	std::vector<std::basic_string<response_char>> object;
	for (int i = 0; i < responseArray.size(); i++) {
		object.push_back(responseArray[i].asString());
	}

	return object;
}