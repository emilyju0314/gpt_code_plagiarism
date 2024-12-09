log::log(acceptor *_acc, std::string _me)
  : pxs (_acc)
{
  name = "paxos-" + _me + ".log";
  logread();
}