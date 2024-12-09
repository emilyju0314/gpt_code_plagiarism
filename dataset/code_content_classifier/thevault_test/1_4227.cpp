void speakerVerification()
{
    // Creates an instance of a speech config with specified subscription key and service region.
    // Replace with your own subscription key and service region (e.g., "westus").
    auto config = SpeechConfig::FromSubscription("YourSubscriptionKey", "YourServiceRegion");

    // Creates a VoiceProfileClient to enroll your voice profile.
    auto client = VoiceProfileClient::FromConfig(config);

    // Creates a text dependent voice profile in one of the supported locales using the client.
    auto profile = client->CreateProfileAsync(VoiceProfileType::TextDependentVerification, "en-us").get();
    auto trainingFiles = vector<string>{ "myVoiceIsMyPassportVerifyMe01.wav", "myVoiceIsMyPassportVerifyMe02.wav", "myVoiceIsMyPassportVerifyMe03.wav" };
    for (auto& trainingFile : trainingFiles)
    {
        auto audioInput = AudioConfig::FromWavFileInput(trainingFile);

        // Enrolls the profile using each training file in turn
        auto result = client->EnrollProfileAsync(profile, audioInput).get();
        if (result->Reason == ResultReason::EnrollingVoiceProfile)
        {
            cout << "Enrolling profile id " << profile->GetId() << endl;
        }
        else if (result->Reason == ResultReason::EnrolledVoiceProfile)
        {
            cout << "Enrolled profile id " << profile->GetId() << endl;

            // Verifies the enrolled profile
            verifySpeaker(config, profile);
            break;
        }
        else if (result->Reason == ResultReason::Canceled)
        {
            auto cancellation = VoiceProfileEnrollmentCancellationDetails::FromResult(result);
            cout << "CANCELED " << profile->GetId() << "ErrorCode= " << (int)cancellation->ErrorCode << endl;
            break;
        }
        cout << "Number of enrollment audios accepted for " << profile->GetId() << " is "<< result->GetEnrollmentInfo(EnrollmentInfoType::EnrollmentsCount) << endl;
        cout << "Number of enrollment audios needed to complete " << profile->GetId() << " is " << result->GetEnrollmentInfo(EnrollmentInfoType::RemainingEnrollmentsCount) << endl;
    }

    if (!profile->GetId().empty())
    {
        client->DeleteProfileAsync(profile).get();
    }
}