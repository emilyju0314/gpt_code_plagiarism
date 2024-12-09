string deposit(HttpClient *client, string amount, string card, string year, string month, string cvc) {
  if (!is_loged_in) {
    throw "deposit: No User Logged In.";
  }

  // API call to string to get token
  // from the dcash wallet to Stripe
  HttpClient *stripe_client = new HttpClient("api.stripe.com", 443, true);
  stripe_client->set_header("Authorization", string("Bearer ") + PUBLISHABLE_KEY);
  stripe_client->set_basic_auth(PUBLISHABLE_KEY, "");

  WwwFormEncodedDict encoder;
  encoder.set("card[number]", card.c_str());
  encoder.set("card[exp_month]", atoi(month.c_str()));
  encoder.set("card[exp_year]", atoi(year.c_str()));
  encoder.set("card[cvc]", atoi(cvc.c_str()));
  string body = encoder.encode();

  HTTPClientResponse *client_response = stripe_client->post("/v1/tokens", body);
  // This method converts the HTTP body into a rapidjson document
  Document *d = client_response->jsonBody();
  bool success = client_response->success();
  delete stripe_client;
  delete client_response;

  if (!success) {
    throw "Stripe Client Response Failed.";
  }

  string token = (*d)["id"].GetString();
  delete d;

  // send amount and token to API server
  encoder = WwwFormEncodedDict();
  encoder.set("stripe_token", token); 
  encoder.set("amount", get_input_amount(amount));
  body = encoder.encode();
  client->set_header("x-auth-token", auth_token);
  client_response = client->post("/deposits", body);

  if (!client_response->success()) {
    delete client_response;
    throw "HTTP Client Response Failed.";
  }

  d = client_response->jsonBody();
  delete client_response;

  assert((*d)["balance"].IsInt());
  int balance = (*d)["balance"].GetInt();
  delete d;
  return get_output_amount(balance);
}