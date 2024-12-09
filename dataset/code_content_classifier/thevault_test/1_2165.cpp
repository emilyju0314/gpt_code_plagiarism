paxos_protocol::status
acceptor::acceptreq(std::string src, paxos_protocol::acceptarg a, bool &r)
{
  // You fill this in for Lab 6
  // Remember to *log* the accept if the proposal is accepted.
  if (a.n >= n_h) {
      n_a = a.n;
      v_a = a.v;
      r = true;
      l->logaccept(n_a, v_a);
  } else {
      r = false;
  }
  
  return paxos_protocol::OK;
}