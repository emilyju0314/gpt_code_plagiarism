void AWSCognitoAuthenticationProvider::InitiateAuthInternalAsync(const AZStd::string& username, const AZStd::string& password
        , AZStd::function<void(Aws::CognitoIdentityProvider::Model::InitiateAuthOutcome outcome)> outcomeCallback)
    {
        std::shared_ptr<Aws::CognitoIdentityProvider::CognitoIdentityProviderClient> cognitoIdentityProviderClient =
            AZ::Interface<IAWSClientAuthRequests>::Get()->GetCognitoIDPClient();

        AZ::JobContext* jobContext = nullptr;
        AWSCore::AWSCoreRequestBus::BroadcastResult(jobContext, &AWSCore::AWSCoreRequests::GetDefaultJobContext);

        AZ::Job* initiateAuthJob = AZ::CreateJobFunction([this, cognitoIdentityProviderClient, username, password, outcomeCallback]()
        {
            // Set Request parameters.
            Aws::CognitoIdentityProvider::Model::InitiateAuthRequest initiateAuthRequest;
            initiateAuthRequest.SetClientId(m_cognitoAppClientId.c_str());
            initiateAuthRequest.SetAuthFlow(Aws::CognitoIdentityProvider::Model::AuthFlowType::USER_PASSWORD_AUTH);

            // Set username and password for Password grant/ Initiate Auth flow.
            Aws::Map<Aws::String, Aws::String> authParameters
            {
                {CognitoUsernameKey, username.c_str()},
                {CognitoPasswordKey, password.c_str()}
            };
            initiateAuthRequest.SetAuthParameters(authParameters);

            Aws::CognitoIdentityProvider::Model::InitiateAuthOutcome initiateAuthOutcome{ cognitoIdentityProviderClient->InitiateAuth(initiateAuthRequest) };
            outcomeCallback(initiateAuthOutcome);
        }, true, jobContext);
        initiateAuthJob->Start();
    }