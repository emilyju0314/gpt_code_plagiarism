inline void requestRoutesSystemActionsReset(App& app)
{
    /**
     * Function handles POST method request.
     * Analyzes POST body message before sends Reset request data to D-Bus.
     */
    BMCWEB_ROUTE(app,
                 "/redfish/v1/Systems/system/Actions/ComputerSystem.Reset/")
        .privileges(redfish::privileges::postComputerSystem)
        .methods(
            boost::beast::http::verb::
                post)([](const crow::Request& req,
                         const std::shared_ptr<bmcweb::AsyncResp>& asyncResp) {
            std::string resetType;
            if (!json_util::readJson(req, asyncResp->res, "ResetType",
                                     resetType))
            {
                return;
            }

            // Get the command and host vs. chassis
            std::string command;
            bool hostCommand;
            if ((resetType == "On") || (resetType == "ForceOn"))
            {
                command = "xyz.openbmc_project.State.Host.Transition.On";
                hostCommand = true;
            }
            else if (resetType == "ForceOff")
            {
                command = "xyz.openbmc_project.State.Chassis.Transition.Off";
                hostCommand = false;
            }
            else if (resetType == "ForceRestart")
            {
                command =
                    "xyz.openbmc_project.State.Host.Transition.ForceWarmReboot";
                hostCommand = true;
            }
            else if (resetType == "GracefulShutdown")
            {
                command = "xyz.openbmc_project.State.Host.Transition.Off";
                hostCommand = true;
            }
            else if (resetType == "GracefulRestart")
            {
                command = "xyz.openbmc_project.State.Host.Transition."
                          "GracefulWarmReboot";
                hostCommand = true;
            }
            else if (resetType == "PowerCycle")
            {
                command = "xyz.openbmc_project.State.Host.Transition.Reboot";
                hostCommand = true;
            }
            else if (resetType == "Nmi")
            {
                doNMI(asyncResp);
                return;
            }
            else
            {
                messages::actionParameterUnknown(asyncResp->res, "Reset",
                                                 resetType);
                return;
            }

            if (hostCommand)
            {
                crow::connections::systemBus->async_method_call(
                    [asyncResp, resetType](const boost::system::error_code ec) {
                        if (ec)
                        {
                            BMCWEB_LOG_ERROR << "D-Bus responses error: " << ec;
                            if (ec.value() ==
                                boost::asio::error::invalid_argument)
                            {
                                messages::actionParameterNotSupported(
                                    asyncResp->res, resetType, "Reset");
                            }
                            else
                            {
                                messages::internalError(asyncResp->res);
                            }
                            return;
                        }
                        messages::success(asyncResp->res);
                    },
                    "xyz.openbmc_project.State.Host",
                    "/xyz/openbmc_project/state/host0",
                    "org.freedesktop.DBus.Properties", "Set",
                    "xyz.openbmc_project.State.Host", "RequestedHostTransition",
                    std::variant<std::string>{command});
            }
            else
            {
                crow::connections::systemBus->async_method_call(
                    [asyncResp, resetType](const boost::system::error_code ec) {
                        if (ec)
                        {
                            BMCWEB_LOG_ERROR << "D-Bus responses error: " << ec;
                            if (ec.value() ==
                                boost::asio::error::invalid_argument)
                            {
                                messages::actionParameterNotSupported(
                                    asyncResp->res, resetType, "Reset");
                            }
                            else
                            {
                                messages::internalError(asyncResp->res);
                            }
                            return;
                        }
                        messages::success(asyncResp->res);
                    },
                    "xyz.openbmc_project.State.Chassis",
                    "/xyz/openbmc_project/state/chassis0",
                    "org.freedesktop.DBus.Properties", "Set",
                    "xyz.openbmc_project.State.Chassis",
                    "RequestedPowerTransition",
                    std::variant<std::string>{command});
            }
        });
}