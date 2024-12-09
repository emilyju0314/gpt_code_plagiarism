inline std::string
    validatePowerMode(const std::shared_ptr<bmcweb::AsyncResp>& aResp,
                      const std::string& modeString)
{
    std::string mode;

    if (modeString == "Static")
    {
        mode = "xyz.openbmc_project.Control.Power.Mode.PowerMode.Static";
    }
    else if (modeString == "MaximumPerformance")
    {
        mode = "xyz.openbmc_project.Control.Power.Mode.PowerMode."
               "MaximumPerformance";
    }
    else if (modeString == "PowerSaving")
    {
        mode = "xyz.openbmc_project.Control.Power.Mode.PowerMode.PowerSaving";
    }
    else
    {
        messages::propertyValueNotInList(aResp->res, modeString, "PowerMode");
    }
    return mode;
}