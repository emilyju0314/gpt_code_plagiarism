IceUtilInternal::Options::StringVector
IceUtilInternal::Options::parse(int argc, const char* const argv[])
{
    StringVector vec;
    for(int i = 0; i < argc; ++i)
    {
        vec.push_back(argv[i]);
    }
    return parse(vec);
}