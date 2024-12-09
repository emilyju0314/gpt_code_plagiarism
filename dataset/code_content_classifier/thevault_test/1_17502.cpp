SenderTy* SenderTy::Find (XPLMPluginID _id, const std::uint32_t _from[4])
{
    SenderAddrTy senderId (_id, _from);
    mapSenderTy::iterator itSender = rcGlob.gmapSender.find(senderId);
    if (itSender != rcGlob.gmapSender.end())
        return &itSender->second;
    return nullptr;
}