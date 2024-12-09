bool ts::TablesLogger::createBinaryFile(const ts::UString& name)
{
    _report.verbose(u"creating %s", {name});
    _binfile.open(name.toUTF8().c_str(), std::ios::out | std::ios::binary);

    if (_binfile) {
        return true;
    }
    else {
        _report.error(u"error creating %s", {name});
        _abort = true;
        return false;
    }
}