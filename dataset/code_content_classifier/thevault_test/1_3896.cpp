static void parse_time_alignment(JSON_Object *root_object)
{
    if (json_object_dotget_value(root_object, "desired.TimeAlignRTSP") != nullptr)
    {
        bool time_align = json_object_dotget_boolean(root_object, "desired.TimeAlignRTSP");
        util::log_info("Time Align RTSP Streams: " + (time_align ? std::string("yes") : std::string("no")));
        update_time_alignment(time_align);
    }
    if (json_object_get_value(root_object, "TimeAlignRTSP") != nullptr)
    {
        bool time_align = json_object_dotget_boolean(root_object, "TimeAlignRTSP");
        util::log_info("Time Align RTSP Streams: " + (time_align ? std::string("yes") : std::string("no")));
        update_time_alignment(time_align);
    }
}