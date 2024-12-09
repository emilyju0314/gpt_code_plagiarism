int gjAPI::ParseRequestDump(const std::string& sInput, std::string* psOutput)
{
    if(!psOutput) return GJ_INVALID_INPUT;

    // read status
    const std::string sStatus = sInput.substr(0, sInput.find_first_of(13));

    // read data
    (*psOutput) = sInput.substr(sStatus.length()+2);

    // check for failed request
    if(sStatus != "SUCCESS")
    {
        gjAPI::ErrorLogAdd("API Error: request was unsuccessful");
        gjAPI::ErrorLogAdd("API Error: " + (*psOutput));
        return GJ_REQUEST_FAILED;
    }

    return GJ_OK;
}