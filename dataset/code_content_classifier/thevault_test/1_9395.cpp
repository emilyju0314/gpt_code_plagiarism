OctoprintApi::OctoprintApi(Client &client, IPAddress octoPrintIp, int octoPrintPort, String apiKey) {
  _client         = &client;
  _apiKey         = apiKey;
  _octoPrintIp    = octoPrintIp;
  _octoPrintPort  = octoPrintPort;
  _usingIpAddress = true;
}