static void parse_streams(JSON_Object *root_object)
{
    if (json_object_dotget_value(root_object, "desired.RawStream") != nullptr)
    {
        rtsp::set_stream_params(rtsp::StreamType::RAW, (bool)json_object_dotget_boolean(root_object, "desired.RawStream"));
    }
    if (json_object_get_value(root_object, "RawStream") != nullptr)
    {
        rtsp::set_stream_params(rtsp::StreamType::RAW, (bool)json_object_dotget_boolean(root_object, "RawStream"));
    }

    if (json_object_dotget_value(root_object, "desired.ResultStream") != nullptr)
    {
        rtsp::set_stream_params(rtsp::StreamType::RESULT, (bool)json_object_dotget_boolean(root_object, "desired.ResultStream"));
    }
    if (json_object_get_value(root_object, "ResultStream") != nullptr)
    {
        rtsp::set_stream_params(rtsp::StreamType::RESULT, (bool)json_object_dotget_boolean(root_object, "ResultStream"));
    }

    if (json_object_dotget_value(root_object, "desired.H264Stream") != nullptr)
    {
        rtsp::set_stream_params(rtsp::StreamType::H264_RAW, (bool)json_object_dotget_boolean(root_object, "desired.H264Stream"));
    }
    if (json_object_dotget_value(root_object, "H264Stream") != nullptr)
    {
        rtsp::set_stream_params(rtsp::StreamType::H264_RAW, (bool)json_object_dotget_boolean(root_object, "H264Stream"));
    }

    if (json_object_dotget_value(root_object, "desired.StreamFPS") != nullptr)
    {
        auto fps = json_object_dotget_number(root_object, "desired.StreamFPS");
        rtsp::set_stream_params(rtsp::StreamType::RAW, (int)fps);
        rtsp::set_stream_params(rtsp::StreamType::RESULT, (int)fps);
    }
    if (json_object_dotget_value(root_object, "StreamFPS") != nullptr)
    {
        auto fps = json_object_dotget_number(root_object, "StreamFPS");
        rtsp::set_stream_params(rtsp::StreamType::RAW, (int)fps);
        rtsp::set_stream_params(rtsp::StreamType::RESULT, (int)fps);
    }

    std::string resolution;
    rtsp::Resolution old_resolution = rtsp::get_resolution(rtsp::StreamType::RAW); // Right now all streams use the same resolution
    bool changed = false;
    if (json_object_dotget_value(root_object, "desired.StreamResolution") != nullptr)
    {
        resolution = std::string(json_object_dotget_string(root_object, "desired.StreamResolution"));
        if (rtsp::is_valid_resolution(std::string(resolution)))
        {
            rtsp::Resolution new_resolution = rtsp::resolution_string_to_enum(resolution);
            rtsp::set_stream_params(rtsp::StreamType::RAW, new_resolution);
            rtsp::set_stream_params(rtsp::StreamType::RESULT, new_resolution);
            changed = old_resolution != new_resolution;
        }
        else
        {
            util::log_error("Invalid resolution setting: " + std::string(resolution));
        }
    }
    if (json_object_dotget_value(root_object, "StreamResolution") != nullptr)
    {
        resolution = std::string(json_object_dotget_string(root_object, "StreamResolution"));
        if (rtsp::is_valid_resolution(std::string(resolution)))
        {
            rtsp::Resolution new_resolution = rtsp::resolution_string_to_enum(resolution);
            rtsp::set_stream_params(rtsp::StreamType::RAW, new_resolution);
            rtsp::set_stream_params(rtsp::StreamType::RESULT, new_resolution);
            changed = old_resolution != new_resolution;
        }
        else
        {
            util::log_error("Invalid resolution setting: " + std::string(resolution));
        }
    }

    // If the resolution changed, we need to restart the pipeline with the new resolution.
    if (changed)
    {
        util::log_info("Old resolution: \"" + rtsp::resolution_to_string(old_resolution) + "\", New resolution: \"" + resolution + "\". Values are different, so updating.");
        restart_model_with_new_resolution(rtsp::resolution_string_to_enum(resolution));
    }
    else
    {
        util::log_info("Old resolution: \"" + rtsp::resolution_to_string(old_resolution) + "\", New resolution: \"" + resolution + "\". Values are the same, so ignoring.");
    }
}