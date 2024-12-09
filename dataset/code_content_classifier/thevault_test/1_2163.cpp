bool
proposer::prepare(unsigned instance, std::vector<std::string> &accepts, 
         std::vector<std::string> nodes,
         std::string &v)
{
  // You fill this in for Lab 6
  // Note: if got an "oldinstance" reply, commit the instance using
  // acc->commit(...), and return false.
  paxos_protocol::prepareres r;  
  paxos_protocol::preparearg arg;
  arg.instance = instance;
  arg.n = my_n;
  
  prop_t highest_n;
  highest_n.n = -1;
  
  for (const auto &node: nodes) {
     handle h(node);
     rpcc *cl = h.safebind();
     int ret = paxos_protocol::ERR;
     if (cl) {
         ret = cl->call(paxos_protocol::preparereq, me, arg, r, rpcc::to(1000));
     }
     if (ret != paxos_protocol::OK) continue;
     if (r.oldinstance) return false;
     if (r.accept) {
         accepts.push_back(node);
         
         // update highest
         if (highest_n.n == -1) {
             highest_n = r.n_a; v = r.v_a;
         } else if (r.n_a > highest_n) {
             highest_n = r.n_a; v = r.v_a;
         }
     }
  }
  return true;
}