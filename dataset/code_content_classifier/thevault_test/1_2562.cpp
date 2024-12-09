void OnInit(SKSE::MessagingInterface::Message* a_msg)
{
	if (a_msg->type == SKSE::MessagingInterface::kDataLoaded) {
		if (rideHorse && patchHorse) {
			const auto reanimateKYWD = RE::TESForm::LookupByID<RE::BGSKeyword>(0x0006F6FB);
			const auto traitGreedy = RE::TESForm::LookupByID<RE::BGSKeyword>(0x000335FA);  //unused keyword in vanilla game.
			if (!reanimateKYWD || !traitGreedy) {
				return;
			}

			if (auto dataHandler = RE::TESDataHandler::GetSingleton(); dataHandler) {
				for (const auto& race : dataHandler->GetFormArray<RE::TESRace>()) {
					if (race && race->HasKeywordString("MagicNoReanimate"sv)) {
						std::string name{ race->GetName() };
						if (SKSE::STRING::insenstiveStringFind(name, "horse"sv)) {
							race->SwapKeyword(reanimateKYWD, traitGreedy);
						}
					}
				}
			}
		}
	}
}