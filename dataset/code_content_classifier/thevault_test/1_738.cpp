inline void requestRoutesSystemsCollection(App& app)
{
    BMCWEB_ROUTE(app, "/redfish/v1/Systems/")
        .privileges(redfish::privileges::getComputerSystemCollection)
        .methods(boost::beast::http::verb::get)(
            [](const crow::Request& /*req*/,
               const std::shared_ptr<bmcweb::AsyncResp>& asyncResp) {
                asyncResp->res.jsonValue["@odata.type"] =
                    "#ComputerSystemCollection.ComputerSystemCollection";
                asyncResp->res.jsonValue["@odata.id"] = "/redfish/v1/Systems";
                asyncResp->res.jsonValue["Name"] = "Computer System Collection";

                crow::connections::systemBus->async_method_call(
                    [asyncResp](const boost::system::error_code ec,
                                const std::variant<std::string>& /*hostName*/) {
                        nlohmann::json& ifaceArray =
                            asyncResp->res.jsonValue["Members"];
                        ifaceArray = nlohmann::json::array();
                        auto& count =
                            asyncResp->res.jsonValue["Members@odata.count"];
                        ifaceArray.push_back(
                            {{"@odata.id", "/redfish/v1/Systems/system"}});
                        count = ifaceArray.size();
                        if (!ec)
                        {
                            BMCWEB_LOG_DEBUG << "Hypervisor is available";
                            ifaceArray.push_back(
                                {{"@odata.id",
                                  "/redfish/v1/Systems/hypervisor"}});
                            count = ifaceArray.size();
                        }
                    },
                    "xyz.openbmc_project.Settings",
                    "/xyz/openbmc_project/network/hypervisor",
                    "org.freedesktop.DBus.Properties", "Get",
                    "xyz.openbmc_project.Network.SystemConfiguration",
                    "HostName");
            });
}