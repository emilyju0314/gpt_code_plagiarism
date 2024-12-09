void DB::dispResult(const std::string& query) throw()
{
    try
    {
        const std::string error = mysql_error(&m_dbhandle);
        // send trap
        m_factory->getSNMP()->sendTrap(klk::snmp::DB_FAILED,
                                       error);

        if (query.empty())
        {
            klk_log(KLKLOG_ERROR,
                    "We have the following error at MySQL DB: %s",
                    error.c_str());
        }
        else
        {
            klk_log(KLKLOG_ERROR,
                    "We have the following error at MySQL DB: %s. Query: %s",
                    error.c_str(), query.c_str());
        }
    }
    catch(...)
    {
        klk_log(KLKLOG_ERROR,
                "Error detected while display MySQL error message");
    }
}