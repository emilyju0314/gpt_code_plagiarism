static vector<string> _list_bones()
{
    string bonefile_dir = _get_bonefile_directory();
    string base_filename = _make_ghost_filename();
    string underscored_filename = base_filename + "_";

    vector<string> filenames = get_dir_files_sorted(bonefile_dir);
    vector<string> bonefiles;
    for (const auto &filename : filenames)
        if (starts_with(filename, underscored_filename)
                                            && !ends_with(filename, ".backup"))
        {
            bonefiles.push_back(bonefile_dir + filename);
            _ghost_dprf("bonesfile %s", (bonefile_dir + filename).c_str());
        }

    string old_bonefile = _get_old_bonefile_directory() + base_filename;
    if (access(old_bonefile.c_str(), F_OK) == 0)
    {
        _ghost_dprf("Found old bonefile %s", old_bonefile.c_str());
        bonefiles.push_back(old_bonefile);
    }

    return bonefiles;
}