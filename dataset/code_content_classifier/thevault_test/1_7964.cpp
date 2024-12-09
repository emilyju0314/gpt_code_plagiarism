string send(HttpClient *client, string to, string amount) {
  if (!is_loged_in) {
    throw "send: No User Logged In.";
  }

  WwwFormEncodedDict encoder;
  encoder.set("to", to);
  encoder.set("amount", get_input_amount(amount));
  string body = encoder.encode();

  client->set_header("x-auth-token", auth_token);
  HTTPClientResponse *response = client->post("/transfers", body);
  string rsp = response->body();
  bool success = response->success();
  delete response;

  if (!success) {
    throw "HTTP Client Response Failed.";
  }

  Document d;
  d.Parse(rsp);
  assert(d["balance"].IsInt());
  return get_output_amount(d["balance"].GetInt());
}