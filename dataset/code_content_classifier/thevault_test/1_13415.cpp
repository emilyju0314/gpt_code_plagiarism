const std::string
Utils::convert2String(const StringList& list, const std::string& sep)
{
    const std::string result = std::accumulate(
        list.begin(),
        list.end(), std::string(""),
        boost::bind<std::string>(
            StringListAccumulator(), _1, _2, sep));

    return result;
}