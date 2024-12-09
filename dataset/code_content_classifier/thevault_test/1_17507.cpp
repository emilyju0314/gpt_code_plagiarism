void ClientProcAcAnim (const std::uint32_t _from[4], size_t _msgLen,
                       const XPMP2::RemoteMsgAcAnimTy& _msgAcAnim)
{
    // Find the sender, bail if we don't know it
    SenderTy* pSender = SenderTy::Find(_msgAcAnim.pluginId, _from);
    if (!pSender) return;
    pSender->lastMsg  = std::chrono::steady_clock::now();

    // Loop all animation data elements in the message
    for (const XPMP2::RemoteAcAnimTy* pAnim = _msgAcAnim.next(_msgLen);
         pAnim;
         pAnim = _msgAcAnim.next(_msgLen, pAnim))
    {
        // Is the aircraft known?
        mapRemoteAcTy::iterator iAc = pSender->mapAc.find(XPMPPlaneID(pAnim->modeS_id));
        if (iAc != pSender->mapAc.end()) {
            // Now require access (for each plane, because we want to give the main thread's flight loop a better change to grab the lock if needed)
            std::lock_guard<std::mutex> lk(gmutexData);
            // known aircraft, update its data
            iAc->second.Update(*pAnim);
        }
    }
}