static string _find_ghost_file()
{
    vector<string> bonefiles = _list_bones();
    if (bonefiles.empty())
        return "";
    return bonefiles[random2(bonefiles.size())];
}