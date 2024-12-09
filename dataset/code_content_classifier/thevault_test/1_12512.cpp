void AWSCognitoUserManagementController::EmailSignUpAsync(const AZStd::string& username, const AZStd::string& password, const AZStd::string& email)
    {
        std::shared_ptr<Aws::CognitoIdentityProvider::CognitoIdentityProviderClient> cognitoIdentityProviderClient =
            AZ::Interface<IAWSClientAuthRequests>::Get()->GetCognitoIDPClient();
        
        AZ::JobContext* jobContext = nullptr;
        AWSCore::AWSCoreRequestBus::BroadcastResult(jobContext, &AWSCore::AWSCoreRequests::GetDefaultJobContext);

        AZ::Job* emailSignUpJob = AZ::CreateJobFunction([this, cognitoIdentityProviderClient, username, password, email]()
        {
            Aws::CognitoIdentityProvider::Model::SignUpRequest signUpRequest;
            signUpRequest.SetClientId(m_cognitoAppClientId.c_str());
            signUpRequest.SetUsername(username.c_str());
            signUpRequest.SetPassword(password.c_str());

            Aws::Vector<Aws::CognitoIdentityProvider::Model::AttributeType> attributes;
            Aws::CognitoIdentityProvider::Model::AttributeType emailAttribute;
            emailAttribute.SetName("email");
            emailAttribute.SetValue(email.c_str());
            attributes.push_back(emailAttribute);
            signUpRequest.SetUserAttributes(attributes);

            Aws::CognitoIdentityProvider::Model::SignUpOutcome signUpOutcome{ cognitoIdentityProviderClient->SignUp(signUpRequest) };
            if (signUpOutcome.IsSuccess())
            {
                Aws::CognitoIdentityProvider::Model::SignUpResult signUpResult{ signUpOutcome.GetResult() };
                AWSCognitoUserManagementNotificationBus::Broadcast(&AWSCognitoUserManagementNotifications::OnEmailSignUpSuccess, signUpResult.GetUserSub().c_str());
                
            }
            else
            {
                Aws::Client::AWSError<Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors> error = signUpOutcome.GetError();
                AWSCognitoUserManagementNotificationBus::Broadcast(&AWSCognitoUserManagementNotifications::OnEmailSignUpFail, error.GetMessage().c_str());
            }
        }, true, jobContext);
        emailSignUpJob->Start();
    }