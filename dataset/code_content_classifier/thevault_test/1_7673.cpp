static ConstPZGBeaconDataRef GetBeaconDataFromMessage(const MessageRef & msg)
{
   FlatCountableRef fcRef;
   if (msg()->FindFlat(PZG_NETWORK_NAME_BEACON_DATA, fcRef).IsOK())
   {
      PZGBeaconDataRef beaconRef(fcRef.GetRefCountableRef(), true);
      if (beaconRef()) return AddConstToRef(beaconRef);
   }

   // Didn't work?  Okay, let's try to unflatten some bytes instead
   PZGBeaconDataRef beaconRef = GetBeaconDataFromPool();
   if ((beaconRef())&&(msg()->FindFlat(PZG_NETWORK_NAME_BEACON_DATA, *beaconRef()).IsError())) beaconRef.Reset();
   return AddConstToRef(beaconRef);
}