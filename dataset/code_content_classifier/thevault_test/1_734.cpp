inline void translatePowerMode(const std::shared_ptr<bmcweb::AsyncResp>& aResp,
                               const std::string& modeValue)
{
    std::string modeString;

    if (modeValue == "xyz.openbmc_project.Control.Power.Mode."
                     "PowerMode.Static")
    {
        aResp->res.jsonValue["PowerMode"] = "Static";
    }
    else if (modeValue == "xyz.openbmc_project.Control.Power.Mode."
                          "PowerMode.MaximumPerformance")
    {
        aResp->res.jsonValue["PowerMode"] = "MaximumPerformance";
    }
    else if (modeValue == "xyz.openbmc_project.Control.Power.Mode."
                          "PowerMode.PowerSaving")
    {
        aResp->res.jsonValue["PowerMode"] = "PowerSaving";
    }
    else if (modeValue == "xyz.openbmc_project.Control.Power.Mode."
                          "PowerMode.OEM")
    {
        aResp->res.jsonValue["PowerMode"] = "OEM";
    }
    else
    {
        // Any other values would be invalid
        BMCWEB_LOG_DEBUG << "PowerMode value was not valid: " << modeValue;
        messages::internalError(aResp->res);
    }
}