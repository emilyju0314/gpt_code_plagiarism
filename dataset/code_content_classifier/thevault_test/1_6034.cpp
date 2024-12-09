int SerialFeedbackData::checkSerialResponseEnd(char * serial_response, int
    number_of_readed_bytes)
{
    if ( _use_string_delimiter || number_of_readed_bytes == 0 )
    {
        char * result = ACE_OS::strstr( serial_response, _delimiter_string->c_str());
        if (result) return 1;
        else return 0;
    }
    else if ( _use_bytesnumber_delimiter )
    {
        _counted_bytes += number_of_readed_bytes;
        if (_counted_bytes >= _bytes_to_read)
            return 1;
        else return 0;
    }

    return 2; //No termination condition has been activated
}