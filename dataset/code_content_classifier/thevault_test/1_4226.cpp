void verifySpeaker(const shared_ptr<SpeechConfig>& config, const shared_ptr<VoiceProfile>& profile)
{
    auto speakerRecognizer = SpeakerRecognizer::FromConfig(config, AudioConfig::FromWavFileInput("myVoiceIsMyPassportVerifyMe04.wav"));

    // Creates the model from the profile to be verified against
    auto model = SpeakerVerificationModel::FromProfile(profile);

    // Verify the given audio sample
    auto result = speakerRecognizer->RecognizeOnceAsync(model).get();
    if (result->Reason == ResultReason::RecognizedSpeaker)
    {
        cout << "Verified voice profile " << result->ProfileId << " score is " << result->GetScore() << endl;
    }
    else if (result->Reason == ResultReason::Canceled)
    {
        auto cancellation = SpeakerRecognitionCancellationDetails::FromResult(result);
        cout << "CANCELED " << profile->GetId() << "ErrorCode= " << (int)cancellation->ErrorCode << endl;
        cout << "CANCELED " << profile->GetId() << "ErrorDetails= " << cancellation->ErrorDetails << endl;
    }
}