bool PZGHeartbeatThreadState :: PeersListMatchesIgnoreOrdering(const Queue<ConstPZGHeartbeatPeerInfoRef> & infoQ) const
{
   if (infoQ.GetNumItems() != _peerIDToIPAddresses.GetNumItems()) return false;
   for (uint32 i=0; i<infoQ.GetNumItems(); i++) if (_peerIDToIPAddresses.ContainsKey(infoQ[i]()->GetPeerID()) == false) return false;
   return true;
}