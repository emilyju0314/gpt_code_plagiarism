int SNetInitializeProvider(Uint32 provider, struct GameData *gameData)
{
	dvlnet_inst = net::abstract_net::make_net(provider);
	return mainmenu_select_hero_dialog(gameData);
}