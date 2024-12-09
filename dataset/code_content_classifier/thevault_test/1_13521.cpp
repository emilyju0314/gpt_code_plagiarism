void Result::push_back_null(const std::string& key) throw()
{
    BOOST_ASSERT(m_results.find(key) == m_results.end());
    m_results.insert(ResultMap::value_type(
                         key,
                         klk::StringWrapper(Parameters::null)));
}