void speakerIdentification()
{
   // Creates an instance of a speech config with specified subscription key and service region.
   // Replace with your own subscription key and service region (e.g., "westus").
   auto config = SpeechConfig::FromSubscription("YourSubscriptionKey", "YourServiceRegion");

   // Creates a VoiceProfileClient to enroll your voice profile.
   auto client = VoiceProfileClient::FromConfig(config);

   // Creates two text independent voice profiles in one of the supported locales.
   auto profile1 = client->CreateProfileAsync(VoiceProfileType::TextIndependentIdentification, "en-us").get();
   auto profile2 = client->CreateProfileAsync(VoiceProfileType::TextIndependentIdentification, "en-us").get();
   cout << "Created profiles " << profile1->GetId() << " and " << profile2->GetId() << " for text independent identification." << endl;

   // Enroll the two profiles
   enrollProfile(client, profile1, AudioConfig::FromWavFileInput("TalkForAFewSeconds16.wav"));
   enrollProfile(client, profile2, AudioConfig::FromWavFileInput("neuralActivationPhrase.wav"));

   // Identify the two profiles after successful enrollments.
   vector<shared_ptr<VoiceProfile>> profiles{ profile1, profile2 };
   identifySpeakers(config, profiles);

   // delete the two profiles after we are done.
   if (!profile1->GetId().empty())
   {
       client->DeleteProfileAsync(profile1).get();
   }
   if (!profile2->GetId().empty())
   {
       client->DeleteProfileAsync(profile2).get();
   }
}