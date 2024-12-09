void
BusTopology::CreateNodes()
{
	std::cout << "Creating " << (unsigned)numNodes << " nodes" << std::endl;

	nodes.Create(numNodes);
	std::cout << "Loading mobility" << std::endl;
	ns2 = Ns2MobilityHelper(traceFile);
	ns2.Install();
}