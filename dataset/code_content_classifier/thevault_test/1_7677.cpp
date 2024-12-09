PZGHeartbeatSourceKey PZGHeartbeatThreadState :: GetKingmakerPeerSource() const
{
   PZGHeartbeatSourceKey ret;

   ZGPeerID minPeerID;
   for (HashtableIterator<PZGHeartbeatSourceKey, PZGHeartbeatSourceStateRef> iter(_onlineSources); iter.HasData(); iter++)
   {
      const PZGHeartbeatPacketWithMetaData & hbPacket = *iter.GetValue()()->GetHeartbeatPacket()();
      const ZGPeerID & nextPID = hbPacket.GetSourcePeerID();
      if (((minPeerID.IsValid() == false)||(nextPID < minPeerID))&&(PeersListMatchesIgnoreOrdering(hbPacket.GetOrderedPeersList()))) 
      {
         ret       = iter.GetKey();
         minPeerID = nextPID;
      }
   }
   return ret;
}