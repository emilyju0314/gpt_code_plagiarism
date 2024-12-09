const std::string Answer::getColumnName(size_t colnum) const

{
    if (colnum >= getCount())
    {
        BOOST_ASSERT(false);
    }

    const char* res = NULL;
    if (m_fields)
	res = m_fields[colnum].name;

    BOOST_ASSERT(res);

    return res;
}