static bool GetAutoProxiesForURL(string& url, vector<SharedProxy>& proxies,
	const string& scheme)
{
	bool shouldUseProxy = true;
	WINHTTP_PROXY_INFO autoProxyInfo;
	ZeroMemory(&autoProxyInfo, sizeof(WINHTTP_PROXY_INFO)); 
	
	WINHTTP_AUTOPROXY_OPTIONS autoProxyOptions;
	ZeroMemory(&autoProxyOptions, sizeof(WINHTTP_AUTOPROXY_OPTIONS)); 
	
	// This type of auto-detection might take several seconds, so
	// if the user specified an auto-configuration URL don't do it.
	// TODO: Maybe we should use this as a fallback later, but it's
	// *very* expensive. A better solution would be to use asyncronous
	// proxy determination.
	if (autoConfigURL.empty() && useProxyAutoConfig)
	{
		autoProxyOptions.dwFlags = WINHTTP_AUTOPROXY_AUTO_DETECT;
		autoProxyOptions.dwAutoDetectFlags = 
			WINHTTP_AUTO_DETECT_TYPE_DHCP | WINHTTP_AUTO_DETECT_TYPE_DNS_A;
	}

	if (!autoConfigURL.empty())
	{
		autoProxyOptions.dwFlags |= WINHTTP_AUTOPROXY_CONFIG_URL;
		autoProxyOptions.lpszAutoConfigUrl = autoConfigURL.c_str();
	}

	// From Chromium:
	// Per http://msdn.microsoft.com/en-us/library/aa383153(VS.85).aspx, it is
	// necessary to first try resolving with fAutoLogonIfChallenged set to false.
	// Otherwise, we fail over to trying it with a value of true.  This way we
	// get good performance in the case where WinHTTP uses an out-of-process
	// resolver.  This is important for Vista and Win2k3.
	wstring wideURL = UTF8ToWide(url);
	autoProxyOptions.fAutoLogonIfChallenged = FALSE;
	BOOL ok = WinHttpGetProxyForUrl(
		httpSession.GetHandle(), wideURL.c_str(), &autoProxyOptions, &autoProxyInfo);

	if (!ok && ERROR_WINHTTP_LOGIN_FAILURE == GetLastError())
	{
		autoProxyOptions.fAutoLogonIfChallenged = TRUE;
		ok = WinHttpGetProxyForUrl(
			httpSession.GetHandle(), wideURL.c_str(), &autoProxyOptions, &autoProxyInfo);
	}
	
	if (ok && autoProxyInfo.dwAccessType == WINHTTP_ACCESS_TYPE_NAMED_PROXY &&
		autoProxyInfo.lpszProxy)
	{
		if (autoProxyInfo.lpszProxyBypass)
		{
			wstring bypassW(autoProxyInfo.lpszProxyBypass);
			string bypassListString(WideToUTF8(bypassW));
			AddToBypassList(bypassListString, bypassList);
		}

		wstring proxyListW(autoProxyInfo.lpszProxy);
		string proxyList(WideToUTF8(proxyListW));

		GetLogger()->Debug("Parsing PAC result proxy list: '%s'", proxyList.c_str());
		ParseProxyList(proxyList, proxies, scheme);
	}
	else if (ok && autoProxyInfo.dwAccessType == WINHTTP_ACCESS_TYPE_NO_PROXY)
	{
		// The only case in which we do not continue to try using a proxy.
		// In this case the auto proxy setup told us to use a direct connection.
		shouldUseProxy = false;
	}
	else
	{
		// Auto proxy failed, so try another method
		string error = "Could not get proxy for url=";
		error.append(url);
		error.append(": ");
		error.append(ErrorCodeToString(GetLastError()));
		Logger::Get("Proxy")->Error(error);
	}

	// Always cleanup
	if (autoProxyInfo.lpszProxy)
		GlobalFree(autoProxyInfo.lpszProxy);
	if (autoProxyInfo.lpszProxyBypass)
		GlobalFree(autoProxyInfo.lpszProxyBypass);

	return shouldUseProxy;
}