static FILE* _make_bones_file(string * return_gfilename)
{
    const string bone_dir = _get_bonefile_directory();
    const string base_filename = _make_ghost_filename(false);

    for (int i = 0; i < GHOST_LIMIT; i++)
    {
        const string g_file_name = make_stringf("%s%s_%d", bone_dir.c_str(),
                                                base_filename.c_str(), i);
        FILE *ghost_file = lk_open_exclusive(g_file_name);
        // need to check file size, so can't open 'wb' - would truncate!

        if (!ghost_file)
        {
            dprf("Could not open %s", g_file_name.c_str());
            continue;
        }

        dprf("found %s", g_file_name.c_str());

        *return_gfilename = g_file_name;
        return ghost_file;
    }

    return nullptr;
}