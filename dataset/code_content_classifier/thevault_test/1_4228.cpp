void identifySpeakers(const shared_ptr<SpeechConfig>& config, const vector<shared_ptr<VoiceProfile>>& profiles)
{
    auto speakerRecognizer = SpeakerRecognizer::FromConfig(config, AudioConfig::FromWavFileInput("TalkForAFewSeconds16.wav"));

    // Creates the model from the profile to be verified against
    auto model = SpeakerIdentificationModel::FromProfiles(profiles);

    // Identify the given audio sample
    auto result = speakerRecognizer->RecognizeOnceAsync(model).get();
    if (result->Reason == ResultReason::RecognizedSpeakers)
    {
        cout << "The most similar voice profile is " << result->ProfileId << " with similarity score " << result->GetScore() << endl;
        auto raw = result->Properties.GetProperty(PropertyId::SpeechServiceResponse_JsonResult);
        cout << "The raw json from the service is " << raw << endl;
    }
}