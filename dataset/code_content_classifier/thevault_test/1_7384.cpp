bytes account::inputData(std::string const& input , bool* isFile)
{
    bytes b = fromHex(input);
    if (isFile)
        *isFile = false;
    if (b.empty())
    {
        if (isFile)
            *isFile = true;
        std::string s = boost::trim_copy_if(contentsString(input), is_any_of(" \t\n"));
        b = fromHex(s);
        if (b.empty())
            b = asBytes(s);
    }
    return b;
}