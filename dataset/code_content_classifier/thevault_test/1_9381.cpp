void
BusTopology::Configure(int argc, char **argv)
{
	LogComponentEnable("NeighborDiscoveryHelper", LOG_LEVEL_ALL);

	CommandLine cmd;
	cmd.AddValue("maxRange", "Wifi range of each node (m)", maxRange);
	cmd.AddValue("numNodes", "Number of nodes", numNodes);
	cmd.AddValue("interval", "Interval of beaconing (s)", interval);
	cmd.AddValue("expiration", "Interval to consider contact lost (s)", expiration);
	cmd.AddValue ("traceFile", "Ns2 movement trace file", traceFile);
	cmd.AddValue ("endSimulation", "End simulation time (h)", endSimulation);
	cmd.Parse(argc, argv);

}