bool ts::AbstractHTTPInputPlugin::handleWebStop(const WebRequest& request)
{
    // Close auto save file if one was open.
    if (_outSave.isOpen()) {
        _outSave.close(*tsp);
    }
    return true;
}