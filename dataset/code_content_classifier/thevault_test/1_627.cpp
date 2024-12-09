void FreesoundClient::authenticationOnBrowser(int mode, Callback cb)
{
	URL url;
	if(mode == 0){url = URIS::uri(URIS::LOGOUT_AUTHORIZE, StringArray());}
	else{url = URIS::uri(URIS::AUTHORIZE, StringArray()); }
	url = url.withParameter("client_id", clientID);
	url = url.withParameter("response_type", "code");
	url.launchInDefaultBrowser();
	cb();
}