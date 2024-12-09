const std::string Utils::replaceAll(
    const std::string& initial,
    const std::string& replaceWhat,
    const std::string& replaceWithWhat)
{
    std::string result(initial);
    std::size_t pos = 0;
    while(1)
    {
        pos = result.find(replaceWhat, pos);
        if (pos == std::string::npos)
            break;
        result.replace(pos,replaceWhat.size(),replaceWithWhat);
        pos++;
    }
    return result;
}