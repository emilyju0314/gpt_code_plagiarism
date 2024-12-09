double
PacketTypeLog::mapTypeToShare(int type) {
  switch (type) {
  case PT_PING: return 1.0;
  case PT_UDP: return 1.0;
  case PT_CBR: return 1.0;
  default: return 1;
  }
}