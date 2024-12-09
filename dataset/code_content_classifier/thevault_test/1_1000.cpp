inline void sendLength (BStream& bout, const OMemStream& m)
{
  size_t len = m.length();
  int_u4 msglen = htonl(m.length());
  if (len < 0xFFFFFFFF) {
    // Normal message len: 4 bytes
    bout.write(&msglen, sizeof(msglen));
  } else {
    // Abnormally large: need 4 bytes (esp), then 8 bytes for real length
    msglen = htonl(int_u4(0xFFFFFFFF)); // ESCape for bigger bytes coming
    bout.write(&msglen, sizeof(msglen));
    int_u8 msglen8 = len;
    int_u8 msglenNBO8 = NetworkToNativeMachineRep(msglen8);
    bout.write(& msglenNBO8, sizeof(msglenNBO8));
  } 
}