InferDetails MakeInferDetails(const std::vector<float>& InAudat,const QString& FilePath,unsigned InSampleRate,int32_t OutSampleRate)
{
    InferDetails Dets;
    Dets.F0 = 0.0f;
    Dets.Speed = 0.0f;
    Dets.Energy = 0.0f;
    Dets.pItem = nullptr; // the mainwindow's function will make an item for us.
    Dets.Prompt = "";
    Dets.SpeakerID = OutSampleRate; // SpeakerID will double as resample when a denoise only job is requested.
    Dets.EmotionID = -1;
    Dets.Denoise = true;
    Dets.Amplification = 1.f;
    Dets.ExportFileName = FilePath;


    Dets.VoiceName = "";
    Dets.ForcedAudio = InAudat;
    Dets.SampleRate = InSampleRate;

    return Dets;

}