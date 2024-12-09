string update_email(string email) {
  // since one client cannot handle two requests,
  // create a new client to do the email API call
  HttpClient *client = new HttpClient(API_SERVER_HOST.c_str(), API_SERVER_PORT);
  WwwFormEncodedDict encoder;

  HTTPClientResponse *response;
  encoder.set("email", email);
  string body = encoder.encode();
  string path = "/users/" + user_id;
  client->set_header("x-auth-token", auth_token);
  response = client->put(path, body);
  string rsp = response->body();

  bool success = response->success();
  delete response;
  delete client;

  if (!success) {
    throw "HTTP Client Response Failed.";
  }


  Document d;
  d.Parse(rsp);
  assert(d["balance"].IsInt());
  int balance = d["balance"].GetInt();

  return get_output_amount(balance);
}