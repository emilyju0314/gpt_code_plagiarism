static inline void checkFTPCommandResponse(CFTP &ftpServer, std::set<std::uint16_t> expectedResults, int count = -1)
{
    if (expectedResults.find(ftpServer.getCommandStatusCode()) == expectedResults.end())
    {
        if (count != -1)
            std::cout << "Count [" << count << "]";
        std::cout << "Status code returned : [" << ftpServer.getCommandStatusCode() << "], when expecting [";
        for (auto result : expectedResults)
            std::cout << result;
        std::cout << "] [Failure]" << std::endl;
        std::cout << "Full response = " << ftpServer.getCommandResponse();
    }
    else
    {
        if (count == -1)
        {
            std::cout << ftpServer.getLastCommand() << " [Success]" << std::endl;
        }
    }
}