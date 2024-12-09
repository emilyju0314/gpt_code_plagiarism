inline void
    processBootOverrideEnable(const std::shared_ptr<bmcweb::AsyncResp>& aResp,
                              const bool bootOverrideEnableSetting)
{
    if (!bootOverrideEnableSetting)
    {
        aResp->res.jsonValue["Boot"]["BootSourceOverrideEnabled"] = "Disabled";
        return;
    }

    // If boot source override is enabled, we need to check 'one_time'
    // property to set a correct value for the "BootSourceOverrideEnabled"
    crow::connections::systemBus->async_method_call(
        [aResp](const boost::system::error_code ec,
                const std::variant<bool>& oneTime) {
            if (ec)
            {
                BMCWEB_LOG_DEBUG << "DBUS response error " << ec;
                messages::internalError(aResp->res);
                return;
            }

            const bool* oneTimePtr = std::get_if<bool>(&oneTime);

            if (!oneTimePtr)
            {
                messages::internalError(aResp->res);
                return;
            }

            bool oneTimeSetting = *oneTimePtr;

            if (oneTimeSetting)
            {
                aResp->res.jsonValue["Boot"]["BootSourceOverrideEnabled"] =
                    "Once";
            }
            else
            {
                aResp->res.jsonValue["Boot"]["BootSourceOverrideEnabled"] =
                    "Continuous";
            }
        },
        "xyz.openbmc_project.Settings",
        "/xyz/openbmc_project/control/host0/boot/one_time",
        "org.freedesktop.DBus.Properties", "Get",
        "xyz.openbmc_project.Object.Enable", "Enabled");
}