PermutationServer (const string& host, int port,
		     Serialization_e ser=SERIALIZE_P0, 
		     bool socket_mode=DUAL_SOCKET,
		     ArrayDisposition_e dis=AS_LIST) :
    MidasServer(host, port, ser, socket_mode, dis)
  { }