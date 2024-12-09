void ClientProcAcRemove (const std::uint32_t _from[4], size_t _msgLen,
                         const XPMP2::RemoteMsgAcRemoveTy& _msgAcRemove)
{
    // Find the sender, bail if we don't know it
    SenderTy* pSender = SenderTy::Find(_msgAcRemove.pluginId, _from);
    if (!pSender) return;
    pSender->lastMsg  = std::chrono::steady_clock::now();

    // Loop over all aircraft contained in the message
    const size_t numAc = _msgAcRemove.NumElem(_msgLen);
    for (size_t i = 0; i < numAc; ++i) {
        const XPMP2::RemoteAcRemoveTy& acRemove = _msgAcRemove.arr[i];
        // Is the aircraft known?
        mapRemoteAcTy::iterator iAc = pSender->mapAc.find(XPMPPlaneID(acRemove.modeS_id));
        if (iAc != pSender->mapAc.end()) {
            // Now require access (for each plane, because we want to give the main thread's flight loop a better change to grab the lock if needed)
            std::lock_guard<std::mutex> lk(gmutexData);
            // mark this a/c for deletion (which must happen in XP's main thread)
            iAc->second.MarkForDeletion();
            // tell the main thread that it shall process removed a/c
            gbSkipAcMaintenance.clear();
        }
    }
}