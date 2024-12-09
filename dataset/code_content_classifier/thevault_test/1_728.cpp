inline void
    modifyCpuPresenceState(const std::shared_ptr<bmcweb::AsyncResp>& aResp,
                           const std::variant<bool>& cpuPresenceState)
{
    const bool* isCpuPresent = std::get_if<bool>(&cpuPresenceState);

    if (isCpuPresent == nullptr)
    {
        messages::internalError(aResp->res);
        return;
    }
    BMCWEB_LOG_DEBUG << "Cpu Present: " << *isCpuPresent;

    if (*isCpuPresent == true)
    {
        nlohmann::json& procCount =
            aResp->res.jsonValue["ProcessorSummary"]["Count"];
        auto procCountPtr =
            procCount.get_ptr<nlohmann::json::number_integer_t*>();
        if (procCountPtr != nullptr)
        {
            // shouldn't be possible to be nullptr
            *procCountPtr += 1;
        }
    }
}