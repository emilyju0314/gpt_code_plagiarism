const char* Answer::getColumn(size_t colnum) const
{
    if (colnum >= getCount())
    {
        BOOST_ASSERT(false);
    }

    const char* res = NULL;
    if (m_row)
	res = m_row[colnum];

    return res;
}