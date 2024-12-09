void gjAPI::UtilTrimString(std::string* psInput)
{
    const size_t iFirst = psInput->find_first_not_of(" \n\r\t");
    if(iFirst != std::string::npos) psInput->erase(0, iFirst);

    const size_t iLast = psInput->find_last_not_of(" \n\r\t");
    if(iLast != std::string::npos) psInput->erase(iLast+1);
}