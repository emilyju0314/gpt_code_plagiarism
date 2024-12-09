StringList ResourcesProtocol::getResourceByType(const std::string& type)
{
    const std::vector<std::string> vec = m_proxy->getResourceByType(type);
    StringList result;
    std::copy(vec.begin(), vec.end(), std::back_inserter(result));
    return result;
}