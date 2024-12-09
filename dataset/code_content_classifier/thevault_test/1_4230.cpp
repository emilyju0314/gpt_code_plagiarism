void ConversationWithMicrophone()
{
    // Creates an instance of a speech config with your subscription key and region.
    // Replace with your own subscription key and service region (e.g., "eastasia").
    // Conversation Transcription is currently available in eastasia and centralus region.
    auto config = SpeechConfig::FromSubscription("YourSubscriptionKey", "YourServiceRegion");
    config->SetProperty("ConversationTranscriptionInRoomAndOnline", "true");

    // Creates an instance of audio config using default microphone as audio input and with audio processing options specified.
    auto audioProcessingOptions = AudioProcessingOptions::Create(AUDIO_INPUT_PROCESSING_ENABLE_DEFAULT,
                                                                PresetMicrophoneArrayGeometry::Circular7,
                                                                SpeakerReferenceChannel::LastChannel);
    auto audioInput = AudioConfig::FromDefaultMicrophoneInput(audioProcessingOptions);

    // Create a conversation from a speech config and conversation Id.
    auto conversation = Conversation::CreateConversationAsync(config, "ConversationTranscriberSamples").get();

    // Create a conversation transcriber given an audio config. If you don't specify any audio input, Speech SDK opens the default microphone.
    auto recognizer = ConversationTranscriber::FromConfig(audioInput);

    // Need to join a conversation before streaming audio.
    recognizer->JoinConversationAsync(conversation).get();

    // Create voice signatures using REST API at https://signature.centralus.cts.speech.microsoft.com by using YourSubscriptionKey
    // and the provided enrollment_audio_katie.wav and enrollment_audio_steve.wav.
    // Replace the below voiceSignatureKatie and voiceSignatureSteve by copy the Signature value from the Response body. The Signature value contains Version, Tag and Data.
    // More details are at https://docs.microsoft.com/azure/cognitive-services/speech-service/how-to-use-conversation-transcription-service
    string voiceSignatureKatie = R"(
               { "Version": 0,
                 "Tag": "VtZQ7sJp8np3AxQC+87WYyBHWsZohWFBN0zgWzzOnpw=",
                 "Data": "BhRRgDCrg6ij5fylg5Jpf5ZW/o/uDWi199DYBbfL1Qdspj77qiuvsVKzG2g5Z9jxKtfdwtkKtaDxog9O6pGD7Ot/8mM1jUtt6LKNz4H9EFvznV/dlFk2Oisg8ZKx/RBlNFMYJkQJnxT/zLfhNWiIF5Y97jH4sgRh2orDg6/567FGktAgcESAbiDx1e7tf0TTLdwijw4p1vJ3qJ2cSCdNbXE9KeUd8sClQLDheCPo+et3rMs5W+Rju3W1SJE6ru9gAoH88CyAfI80+ysAecH3GPJYM+j1uhvmWoKIrSfS40BYOe6AUgLNb3a4Pue4oGAmuAyWfwpP1uezleSanpJc73HT91n2UsaHrQj5eK6uuBCjwmu+JI3FT+Vo6JhAARHecdb70U1wyW9vv5t0Q3tV1WNiN/30qSVydDtyrSVpgBiIwlj41Ua22JJCOMrPl7NKLnFmeZ4Hi4aIKoHAxDvrApteL60sxLX/ADAtYCB3Y6iagDyR1IOsIlbaPhL0rQDnC/0z65k7BDekietFNzvvPVoIwJ26GHrXFYYwZe3alVvCsXTpZGBknvSiaCalrixnyGqYo0nG/cd/LodEEIht/PWoFkNlbABqHMbToeI/6j+ICKuVJgTDtcsDQiWKSvrQp9kTSv+cF3LyPVkbks0JvbQhj4AkAv7Rvymgnsu6o8gGyxTX0kxujqCMPCzgFrVd"
               })";
    string voiceSignatureSteve = R"(
                { "Version": 0,
                  "Tag": "HbIvzbfAWjeR/3R+WvUEoeid1AbDaHNOMWItgs7mTxc=",
                  "Data": "DizY04Z7PH/sYu2Yw2EcL4Mvj1GnEDOWJ/DhXHGdQJsQ8/zDc13z1cwllbEo5OSr3oGoKEHLV95OUA6PgksZzvTkf42iOFEv3yifUNfYkZuIzStZoDxWu1H1BoFBejqzSpCYyvqLwilWOyUeMn+z+E4+zXjqHUCyYJ/xf0C3+58kCbmyA55yj7YZ6OtMVyFmfT2GLiXr4YshUB14dgwl3Y08SRNavnG+/QOs+ixf3UoZ6BC1VZcVQnC2tn2FB+8v6ehnIOTQedo++6RWIB0RYmQ8VaEeI0E4hkpA1OxQ9f2gBVtw3KZXWSWBz8sXig2igpwMsQoFRmmIOGsu+p6tM8/OThQpARZ7OyAxsurzmaSGZAaXYt0YwMdIIXKeDBF6/KnUyw+NNzku1875u2Fde/bxgVvCOwhrLPPuu/RZUeAkwVQge7nKYNW5YjDcz8mfg4LfqWEGOVCcmf2IitQtcIEjY3MwLVNvsAB6GT2es1/1QieCfQKy/Tdu8IUfEvekwSCxSlWhfVrLjRhGeWa9idCjsngQbNkqYUNdnIlidkn2DC4BavSTYXR5lVxV4SR/Vvj8h4N5nP/URPDhkzl7n7Tqd4CGFZDzZzAr7yRo3PeUBX0CmdrKLW3+GIXAdvpFAx592pB0ySCv5qBFhJNErEINawfGcmeWZSORxJg1u+agj51zfTdrHZeugFcMs6Be"
                 })";

    // creates a participant
    auto katie = Participant::From("katie@example.com", "en-us", voiceSignatureKatie);

    // creates another participant
    auto steve = Participant::From("steve@example.com", "en-us", voiceSignatureSteve);

    // Adds katie as a participant to the conversation.
    conversation->AddParticipantAsync(katie).get();

    // Adds steve as a participant to the conversation.
    conversation->AddParticipantAsync(steve).get();

    // a promise for synchronization of recognition end.
    promise<void> recognitionEnd;

    // Subscribes to events.
    recognizer->Transcribing.Connect([](const ConversationTranscriptionEventArgs& e)
    {
        cout << "TRANSCRIBING: Text=" << e.Result->Text << std::endl;
    });

    recognizer->Transcribed.Connect([](const ConversationTranscriptionEventArgs& e)
    {
        if (e.Result->Reason == ResultReason::RecognizedSpeech)
        {
            cout << "Transcribed: Text=" << e.Result->Text << std::endl
                << "  Offset=" << e.Result->Offset() << std::endl
                << "  Duration=" << e.Result->Duration() << std::endl
                << "  UserId=" << e.Result->UserId << std::endl;
        }
        else if (e.Result->Reason == ResultReason::NoMatch)
        {
            cout << "NOMATCH: Speech could not be recognized." << std::endl;
        }
    });

    recognizer->Canceled.Connect([&recognitionEnd](const ConversationTranscriptionCanceledEventArgs& e)
    {
        switch (e.Reason)
        {
        case CancellationReason::EndOfStream:
            cout << "CANCELED: Reached the end of the file." << std::endl;
            break;

        case CancellationReason::Error:
            cout << "CANCELED: ErrorCode=" << (int)e.ErrorCode << std::endl;
            cout << "CANCELED: ErrorDetails=" << e.ErrorDetails << std::endl;
            recognitionEnd.set_value();
            break;

        default:
            cout << "unknown reason ?!" << std::endl;
        }
    });

    recognizer->SessionStopped.Connect([&recognitionEnd](const SessionEventArgs& e)
    {
        cout << "SESSION: " << e.SessionId << " stopped." << std::endl;
        recognitionEnd.set_value(); // Notify to stop recognition.
    });

    // Starts transcribing.
    recognizer->StartTranscribingAsync().wait();

    // Waits for transcribing to end.
    recognitionEnd.get_future().wait();

    // Stops transcribing. This is optional.
    recognizer->StopTranscribingAsync().wait();
}