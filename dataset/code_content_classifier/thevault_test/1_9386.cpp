void
BusTopology::InstallApplications()
{
	std::cout << "Installing applications at each node" << std::endl;
	uint16_t port = 4000;
	Time interPacketInterval = Seconds (interval);
	Time nodeExpiration = Seconds(expiration);

	NeighborDiscoveryHelper ndh(interPacketInterval, port, nodeExpiration);

	// Applications will start when the Aircraft is flying above the ocean
	for(int i = 0; i < (int) nodes.GetN(); ++i)
	{
		double at = ns2.getNodeIdFirstTime(i);
		ApplicationContainer apps = ndh.Install(nodes.Get(i));
		apps.Start(Seconds (at));
		apps.Stop(Hours (endSimulation));
	}
}