void ts::ATSCEAC3AudioDescriptor::clear()
{
    mixinfoexists = false;
    full_service = false;
    audio_service_type = 0;
    number_of_channels = 0;
    bsid.reset();
    priority.reset();
    mainid.reset();
    asvc.reset();
    substream1.reset();
    substream2.reset();
    substream3.reset();
    language.clear();
    language_2.clear();
    substream1_lang.clear();
    substream2_lang.clear();
    substream3_lang.clear();
    additional_info.clear();
}