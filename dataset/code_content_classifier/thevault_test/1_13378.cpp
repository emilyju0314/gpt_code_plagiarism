std::string LibFactory::getPathFromDescription(
    const std::string& id,
    const std::string& fname) const
{
    std::string res = "";
    // process only files with .xml extension
    if (base::Utils::getFileExt(fname) != "xml")
    {
        // nothing to do
        return res;
    }
    try
    {
        XML xml;
        xml.parseFromFile(fname);
        std::string xpath_id = "/klkdata/module/id";
        if (xml.getValue(xpath_id) == id)
        {
            std::string xpath_lib = "/klkdata/module/lib_path";
            // found it
            res = xml.getValue(xpath_lib);
        }
    }
    catch(const std::exception& err)
    {
        // ignore errors
        klk_log(KLKLOG_ERROR, "Got an error while processing '%s': %s",
                fname.c_str(), err.what());
    }

    return res;
}