static MessageRef CreateBeaconDataMessage(const ConstPZGBeaconDataRef & beaconData, bool serializeBeaconData, const PZGMulticastMessageTag & sourceTag)
{
   MessageRef msg = GetMessageFromPool(PZG_NETWORK_COMMAND_SET_BEACON_DATA);
   if (msg() == NULL) return MessageRef();

   if (beaconData())
   {
      if (serializeBeaconData)
      {
         FlatCountableRef fcRef(CastAwayConstFromRef(beaconData));
         if (msg()->AddFlat(PZG_NETWORK_NAME_BEACON_DATA, fcRef).IsError()) return MessageRef();
      }
      else if (msg()->AddFlat(PZG_NETWORK_NAME_BEACON_DATA, *beaconData()).IsError()) return MessageRef();
   }

   if ((sourceTag.IsValid())&&(msg()->AddFlat(PZG_NETWORK_NAME_MULTICAST_TAG, sourceTag).IsError())) return MessageRef();

   return msg;
}