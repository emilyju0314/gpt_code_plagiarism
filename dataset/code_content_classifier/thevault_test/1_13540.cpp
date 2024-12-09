void FolderInfo::fillOutMessage(const IMessagePtr& out) const
{
    // all check should be done before
    // at FolderInfo::check
    // now we should generate an unique name
    // and create a folder for the file
    const std::string folder = getPath() +
        base::Utils::getCurrentTime("/%Y/%m/%d/%H");
    // create it
    base::Utils::mkdir(folder);
    // path for the file
    const std::string name = base::Utils::generateUUID() + ".bin";
    const std::string path = folder + "/" + name;
    // add the path into our DB
    db::DB db(getFactory());
    db.connect();
    // CREATE PROCEDURE `klk_file_add_child` (
    // INOUT file VARCHAR(40),
    // IN name VARCHAR(40),
    // IN file_path VARCHAR(255),
    // IN host VARCHAR(40),
    // IN parent_uuid VARCHAR(40),
    // OUT return_value INT
    db::Parameters params;
    params.add("@file");
    params.add("@name", name);
    params.add("@file_path", path);
    params.add("@host", db.getHostUUID());
    params.add("@parent_uuid", getUUID());
    params.add("@return_value");
    db::Result res = db.callSimple("klk_file_add_child", params);
    if (res["@return_value"].toInt() != 0)
    {
        throw Exception(__FILE__, __LINE__,
                        "Adding a child failed. "
                        "Parent Name: %s. Parent Path: %s",
                        getName().c_str(),
                        getPath().c_str());
    }

    const std::string file_uuid = getFileUUID();
    // set uuid of current file for future end time update
    setFileUUID(res["@file"].toString());
    // process end time
    if (!file_uuid.empty())
    {
        // CREATE PROCEDURE `klk_file_update_end_time` (
	// IN file VARCHAR(40),
	// OUT return_value INT
        params.clear();
        params.add("@file", file_uuid);
        params.add("@return_value");
        res = db.callSimple("klk_file_update_end_time", params);
        if (res["@return_value"].toInt() != 0)
        {
            throw Exception(__FILE__, __LINE__,
                            "Updating time for a child failed. "
                            "Parent Name: %s. Parent Path: %s",
                            getName().c_str(),
                            getPath().c_str());
        }
    }

    // All is fine. Fill output
    mod::Info::fillOutMessage(out);
    // we set a virtual path at the output
    out->setData(msg::key::FILEPATH, path);
}