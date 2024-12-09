void AWSCognitoAuthenticationProvider::PasswordGrantMultiFactorConfirmSignInAsync(const AZStd::string& username, const AZStd::string& confirmationCode)
    {
        std::shared_ptr<Aws::CognitoIdentityProvider::CognitoIdentityProviderClient> cognitoIdentityProviderClient =
            AZ::Interface<IAWSClientAuthRequests>::Get()->GetCognitoIDPClient();

        AZ::JobContext* jobContext = nullptr;
        AWSCore::AWSCoreRequestBus::BroadcastResult(jobContext, &AWSCore::AWSCoreRequests::GetDefaultJobContext);
        AZ::Job* confirmSignInJob = AZ::CreateJobFunction([this, cognitoIdentityProviderClient, confirmationCode, username]()
        {
            // Set Request parameters for SMS Multi factor authentication.
            // Note: Email MFA is no longer supported by Cognito, use SMS as MFA
            Aws::CognitoIdentityProvider::Model::RespondToAuthChallengeRequest respondToAuthChallengeRequest;
            respondToAuthChallengeRequest.SetClientId(m_cognitoAppClientId.c_str());
            respondToAuthChallengeRequest.AddChallengeResponses(CognitoSmsMfaCodeKey, confirmationCode.c_str());
            respondToAuthChallengeRequest.AddChallengeResponses(CognitoUsernameKey, username.c_str());
            respondToAuthChallengeRequest.SetChallengeName(Aws::CognitoIdentityProvider::Model::ChallengeNameType::SMS_MFA);
            respondToAuthChallengeRequest.SetSession(m_session.c_str());

            Aws::CognitoIdentityProvider::Model::RespondToAuthChallengeOutcome respondToAuthChallengeOutcome{ cognitoIdentityProviderClient->RespondToAuthChallenge(respondToAuthChallengeRequest) };
            if (respondToAuthChallengeOutcome.IsSuccess())
            {
                Aws::CognitoIdentityProvider::Model::RespondToAuthChallengeResult respondToAuthChallengeResult{ respondToAuthChallengeOutcome.GetResult() };
                if (respondToAuthChallengeResult.GetChallengeName() == Aws::CognitoIdentityProvider::Model::ChallengeNameType::NOT_SET)
                {
                    Aws::CognitoIdentityProvider::Model::AuthenticationResultType authenticationResult = respondToAuthChallengeResult.GetAuthenticationResult();
                    UpdateTokens(authenticationResult);
                    AuthenticationProviderNotificationBus::Broadcast(
                        &AuthenticationProviderNotifications::OnPasswordGrantMultiFactorConfirmSignInSuccess, m_authenticationTokens);
                }
            }
            else
            {
                Aws::Client::AWSError<Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors> error = respondToAuthChallengeOutcome.GetError();
                AuthenticationProviderNotificationBus::Broadcast(&AuthenticationProviderNotifications::OnPasswordGrantMultiFactorConfirmSignInFail, error.GetMessage().c_str());
            }
        }, true, jobContext);
        confirmSignInJob->Start();
    }