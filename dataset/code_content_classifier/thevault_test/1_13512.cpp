void init_klksnmphttpstreamer(void)
{
    try
    {
        // do table initialization
        init_table();
    }
    catch(const std::exception& err)
    {
        const std::string msg =
            std::string("Error during initialization: ") +
            err.what() + "\n";
        DEBUGMSGTL((SNMPID.c_str(), "%s",  msg.c_str()));
    }
    catch(...)
    {
        DEBUGMSGTL((SNMPID.c_str(), "%s",
                    "Unknown error during initialization\n"));
    }
}