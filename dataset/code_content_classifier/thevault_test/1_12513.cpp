void AWSCognitoUserManagementController::ConfirmSignUpAsync(const AZStd::string& username, const AZStd::string& confirmationCode)
    {
        std::shared_ptr<Aws::CognitoIdentityProvider::CognitoIdentityProviderClient> cognitoIdentityProviderClient =
            AZ::Interface<IAWSClientAuthRequests>::Get()->GetCognitoIDPClient();
 
        AZ::JobContext* jobContext = nullptr;
        AWSCore::AWSCoreRequestBus::BroadcastResult(jobContext, &AWSCore::AWSCoreRequests::GetDefaultJobContext);

        AZ::Job* confirmSignUpJob = AZ::CreateJobFunction([this, cognitoIdentityProviderClient, username, confirmationCode]()
        {
            Aws::CognitoIdentityProvider::Model::ConfirmSignUpRequest confirmSignupRequest;
            confirmSignupRequest.SetClientId(m_cognitoAppClientId.c_str());
            confirmSignupRequest.SetUsername(username.c_str());
            confirmSignupRequest.SetConfirmationCode(confirmationCode.c_str());

            Aws::CognitoIdentityProvider::Model::ConfirmSignUpOutcome confirmSignupOutcome{ cognitoIdentityProviderClient->ConfirmSignUp(confirmSignupRequest) };
            if (confirmSignupOutcome.IsSuccess())
            {
                AWSCognitoUserManagementNotificationBus::Broadcast(&AWSCognitoUserManagementNotifications::OnConfirmSignUpSuccess);
            }
            else
            {
                Aws::Client::AWSError<Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors> error = confirmSignupOutcome.GetError();
                AWSCognitoUserManagementNotificationBus::Broadcast(&AWSCognitoUserManagementNotifications::OnConfirmSignUpFail, error.GetMessage().c_str());
            }
        }, true, jobContext);
        confirmSignUpJob->Start();
    }