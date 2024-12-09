StringList ModuleFactory::getModuleIDs()
{
    StringList list;

    boost::filesystem::path folder(dir::SHARE);
    folder /= "modules";
    // default construction yields past-the-end
    boost::filesystem::directory_iterator end_itr;
    for (boost::filesystem::directory_iterator itr(folder);
         itr != end_itr; itr++)
    {
        if (!boost::filesystem::is_regular_file(itr->status()))
            continue; // ignore directories
        // process only files with .xml extension
        boost::filesystem::path file(itr->path());
        if (file.extension() != ".xml")
            continue;

        XML xml;
        try
        {
            xml.parseFromFile(file.string());
        }
        catch(const std::exception& err)
        {
            klk_log(KLKLOG_ERROR, "Failed to get module info from '%s': %s",
                    file.string().c_str(), err.what());
            continue;
        }

        const std::string id = xml.getValue("/klkdata/module/id");
        list.push_back(id);
    }
    return list;
}