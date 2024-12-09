void logout(HttpClient *client) {
  if (!is_loged_in) {
    exit(0);
  }

  string path = "/auth-tokens/" + user_id;
  client->set_header("x-auth-token", auth_token);
  HTTPClientResponse *client_response = client->del(path);
  delete client_response;

  // the server show returns nothing
  exit(0);  // exit the program
}