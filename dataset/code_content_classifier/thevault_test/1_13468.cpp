const std::string
OptionConverter::getOption(const std::string& key,
                           const OptionMap& map) const
{
    OptionMap::const_iterator find = map.find(key);
    BOOST_ASSERT(find != map.end());
    return find->second;
}