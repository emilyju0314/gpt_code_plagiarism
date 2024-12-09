static const std::string catPaths(const std::string a, const std::string b)
{
    if ( !a.size() ) {
        return b;
    }
    if ( a[a.size()-1] != '/' ) {
        return a + "/" + b;
    }
    return a + b;
}