void enrollProfile(std::shared_ptr<VoiceProfileClient> client, std::shared_ptr <VoiceProfile> profile, std::shared_ptr <AudioConfig> audioConfig)
{
   ResultReason reason = ResultReason::EnrollingVoiceProfile;
   std::shared_ptr<VoiceProfileEnrollmentResult> result;

   // 20 seconds of spoken audio is required for a valid enrollment, loop until the service completes enrollment
   while (reason == ResultReason::EnrollingVoiceProfile)
   {
       result = client->EnrollProfileAsync(profile, audioConfig).get();
       reason = result->Reason;
   }
   if (reason == ResultReason::EnrolledVoiceProfile)
   {
       cout << "Enrolled profile " << profile->GetId() << endl;
   }
   else if (reason == ResultReason::Canceled)
   {
       cout << "Profile enrollment failed!" << endl;
       auto cancellation = CancellationDetails::FromResult(result);
       cout << "CANCELED: Reason=" << (int)cancellation->Reason << std::endl;

       if (cancellation->Reason == CancellationReason::Error) {
          cout << "CANCELED: ErrorCode= " << (int)cancellation->ErrorCode << std::endl;
          cout << "CANCELED: ErrorDetails=" << cancellation->ErrorDetails << std::endl;
       }
   }
   else
   {
       cout << "Profile enrollment failed, result: " << result->Text << endl;
   }
}