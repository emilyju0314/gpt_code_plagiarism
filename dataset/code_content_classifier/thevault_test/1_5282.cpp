bool ts::AbstractHTTPInputPlugin::handleWebStart(const WebRequest& request, size_t size)
{
    // Get complete MIME type.
    const UString mime(request.mimeType());

    // Print a message.
    tsp->verbose(u"downloading from %s", {request.finalURL()});
    tsp->verbose(u"MIME type: %s, expected size: %s", {mime.empty() ? u"unknown" : mime, size == 0 ? u"unknown" : UString::Format(u"%d bytes", {size})});
    if (!mime.empty() && !mime.similar(u"video/mp2t")) {
        tsp->warning(u"MIME type is %d, maybe not a valid transport stream", {mime});
    }

    // Create the auto-save file when necessary.
    const UString url(request.finalURL());
    if (!_autoSaveDir.empty() && !url.empty()) {
        const UString name(_autoSaveDir + PathSeparator + BaseName(url));
        tsp->verbose(u"saving input TS to %s", {name});
        // Display errors but do not fail, this is just auto save.
        _outSave.open(name, TSFile::WRITE | TSFile::SHARED, *tsp);
    }

    // Reinitialize partial packet if some bytes were left from a previous iteration.
    _partial_size = 0;
    return true;
}