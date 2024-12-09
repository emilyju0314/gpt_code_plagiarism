void
proposer::accept(unsigned instance, std::vector<std::string> &accepts,
        std::vector<std::string> nodes, std::string v)
{
  // You fill this in for Lab 6
  paxos_protocol::acceptarg arg;
  arg.instance = instance;
  arg.n = my_n;
  arg.v = v;

  bool accepted;

  for (const auto & node: nodes) {
     handle h(node);
     rpcc *cl = h.safebind();
     int ret = paxos_protocol::ERR;
     if (cl) {
        ret = cl->call(paxos_protocol::acceptreq, me, arg, accepted, rpcc::to(1000));
     }
     if (ret == paxos_protocol::OK && accepted) {
         accepts.push_back(node);
     }
  }
}