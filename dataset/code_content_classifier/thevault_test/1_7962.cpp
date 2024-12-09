string auth(HttpClient *client, string username, string password, string email) {
  client->set_basic_auth(username, password);
  WwwFormEncodedDict encoder = WwwFormEncodedDict();
  encoder.set("username", username); 
  encoder.set("password", password);
  string body = encoder.encode();

  HTTPClientResponse *response;
  response = client->post("/auth-tokens", body);
  string rsp = response->body();
  bool success = response->success();
  delete response;

  if (!success) {
    throw "HTTP Client Response Failed.";
  }

  Document d;
  d.Parse(rsp);
  assert(d["auth_token"].IsString());
  assert(d["user_id"].IsString());
  auth_token = d["auth_token"].GetString();
  user_id = d["user_id"].GetString();
  
  is_loged_in = true;
  return update_email(email);
}