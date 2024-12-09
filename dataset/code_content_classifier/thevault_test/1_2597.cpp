int callNosCmd(const char* body, const NosApp* app, const NosCmd* cmd) {
  auto req = cmd->request->New();
  auto res = cmd->reply->New();
  req->CopyFrom(*cmd->request);
  res->CopyFrom(*cmd->reply);

  auto num_fields = req->GetDescriptor()->field_count();
  if ((num_fields > 0) && !body) {
    printRequestDefinition(req);
    // return 3;
  }

  if (body) {
    auto status = JsonStringToMessage(body, req);
    if (status.ok()) {
      std::cout << "Request:" << endl;
      req->PrintDebugString();
      std::cout << endl;
    } else {
      std::cerr << "Json parsing issue: " << status << std::endl;
      return 1;
    }
  }

  // init the client
  NuggetClient client(CITADEL_DEV);
  uint32_t rv;

  client.Open();

  if (!client.IsOpen()) {
    std::cerr << "Error opening client " << CITADEL_DEV << std::endl;
    return 2;
  }

  // convert request to vector<uint8_t>
  std::string sreq;
  req->SerializeToString(&sreq);
  std::vector<uint8_t> vecreq(sreq.begin(), sreq.end());

  std::vector<uint8_t> vecres;
  vecres.resize(MAX_RESPONSE_SIZE);

  // call nos lib
  rv = client.CallApp(app->id, cmd->id, vecreq, &vecres);

  // print result
  std::string response_str(vecres.begin(), vecres.end());
  res->ParseFromString(response_str);
  std::cout << "Response:" << endl;
  res->PrintDebugString();

  // close the client
  client.Close();

  return rv;
}