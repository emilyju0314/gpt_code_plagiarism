bool Services::HandleExamplePost (struct mg_connection *nc, struct mg_http_message *hm) {
  // const struct mg_str *body = hm->query_string.len > 0 ? &hm->query_string : &hm->body;
  // std::string msg(body->p, body->len);
  // struct mg_str &body = hm->body;
  // std::string msg(body.ptr, body.len);

  // std::istringstream is(msg);
  Json::Value root;

  printf ("%s\n", __func__);

  if (!ExtractJsonFromBody(root, nc, hm)) {
    SendError(nc, 403, "Invalid Request");
  }
    
  printf ("Extracting data from the JSON object:\n");
  std::string textField (root["text"].asString());
  std::string dropdownField (root["dropdownValue"].asString());
  std::string radioOptionField (root["radioOption"].asString());
  std::vector<std::string> checkedOptionField;
  if (root["checkedOption"].isArray()) {
    int index{0};
    for (auto val : root["checkedOption"]) {
      checkedOptionField.push_back(val.asString());
      printf ("checkedOption[%d]: %s\n", index++, val.asCString());
    }
  }
   
  printf ("dropdownValue: %s\n", dropdownField.c_str());
  printf ("text: %s\n", textField.c_str());
  printf ("radioOption: %s\n", radioOptionField.c_str());

  // Our data is stored in our variables now.   We could perform standard back end tasks with this data.

  SendReply(nc, 200);
  printf ("Ack POST\n");
  return true;
}