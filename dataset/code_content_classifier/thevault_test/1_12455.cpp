void GoogleAuthenticationProvider::DeviceCodeGrantSignInAsync()
    {
        AZStd::string body = AZStd::string::format("%s=%s&%s=%s", OAuthClientIdBodyKey, m_settings->m_appClientId.c_str()
            , OAuthScopeBodyKey, OAuthScopeBodyValue);

        // Set headers and body for device sign in http requests.
        AZStd::map<AZStd::string, AZStd::string> headers;
        headers[OAuthContentTypeHeaderKey] = OAuthContentTypeHeaderValue;
        headers[OAuthContentLengthHeaderKey] = AZStd::to_string(body.length());

        HttpRequestor::HttpRequestorRequestBus::Broadcast(&HttpRequestor::HttpRequestorRequests::AddRequestWithHeadersAndBody, m_settings->m_oAuthCodeURL
            , Aws::Http::HttpMethod::HTTP_POST, headers, body
            , [this](const Aws::Utils::Json::JsonView& jsonView, Aws::Http::HttpResponseCode responseCode)
            {
                if (responseCode == Aws::Http::HttpResponseCode::OK)
                {
                    m_cachedDeviceCode = jsonView.GetString(OAuthDeviceCodeBodyKey).c_str();
                    AuthenticationProviderNotificationBus::Broadcast(&AuthenticationProviderNotifications::OnDeviceCodeGrantSignInSuccess
                        , jsonView.GetString(OAuthUserCodeResponseKey).c_str(), jsonView.GetString(GoogleVerificationUrlResponseKey).c_str()
                        , jsonView.GetInteger(OAuthExpiresInResponseKey));
                }
                else
                {
                    AuthenticationProviderNotificationBus::Broadcast(&AuthenticationProviderNotifications::OnDeviceCodeGrantSignInFail
                        , jsonView.GetString(OAuthErrorResponseKey).c_str());
                }
            }
        );
    }