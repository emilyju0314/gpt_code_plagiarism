bool ts::hls::InputPlugin::setReceiveTimeout(MilliSecond timeout)
{
    if (timeout > 0) {
        _webArgs.receiveTimeout = _webArgs.connectionTimeout = timeout;
    }
    return true;
}