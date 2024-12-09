SenderTy::SenderTy (const std::string& _from, const XPMP2::RemoteMsgSettingsTy& _s) :
sFrom(_from), bLocal(_s.bLocalSender),
settings(_s), lastMsg(std::chrono::steady_clock::now())
{
    // Remove port number from IP adress
    const size_t posColon = sFrom.rfind(':');
    if (posColon != std::string::npos)
        sFrom.erase(posColon);
}