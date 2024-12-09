OctoprintApi::OctoprintApi(Client &client, char *octoPrintUrl, int octoPrintPort, String apiKey) {
  _client         = &client;
  _apiKey         = apiKey;
  _octoPrintUrl   = octoPrintUrl;
  _octoPrintPort  = octoPrintPort;
  _usingIpAddress = false;
}