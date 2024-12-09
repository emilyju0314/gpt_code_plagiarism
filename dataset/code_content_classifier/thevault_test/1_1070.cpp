void SwapDisconnectCommand()
{
//	DevMsg("SwapDisconnectCommand\n");
	ConCommand *_realDisconnectCommand = dynamic_cast< ConCommand* >( g_pCVar->FindCommand( "disconnect" ) );
	ConCommand *_DADisconnectCommand = dynamic_cast< ConCommand* >( g_pCVar->FindCommand( "__da_disconnect" ) );

	if (!_realDisconnectCommand)
		return;
	if (!_DADisconnectCommand)
		return;

	_realDisconnectCommand->Shutdown();
	_realDisconnectCommand->Create("__real_disconnect", "" );
	_realDisconnectCommand->Init();

	_DADisconnectCommand->Shutdown();
	_DADisconnectCommand->Create("disconnect", "Disconnect game from server." );
	_DADisconnectCommand->Init();
}