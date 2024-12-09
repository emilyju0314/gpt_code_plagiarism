void LCU::League::Client::UX::SetAffinity(Session* session, std::string affinity)
{
	// Takes "newAffinity" as a string
	SerializedValue data(SerializedValueType::OBJECT);
	data.child("newAffinity", true) = affinity;

	LCU::Network::HTTP::Post(session, "/riotclient/affinity", data.getJSON());
}