void UpdateAssociatedDevices()
{
  ClientMapType::iterator it = clients.begin();

  while (it != clients.end()) {
    client_state_t *state = it->second;
    ClientStateToJson(state);
    ++it;
  }
}