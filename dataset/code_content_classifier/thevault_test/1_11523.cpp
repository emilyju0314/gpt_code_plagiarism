static void exitWithError(std::string errMsg)
{
    // Display error and exit.
    std::cout.flush();
    std::cerr << errMsg << std::endl;
    exit(EXIT_FAILURE);
}