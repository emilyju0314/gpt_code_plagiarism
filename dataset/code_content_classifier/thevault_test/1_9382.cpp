void
BusTopology::Run()
{
	CreateNodes();
	CreateDevices();
	InstallInternetStack();
	InstallApplications();

	InitializeGraph();

	double totalTime = endSimulation * 3600;	// Seconds

	std::cout << "Starting simulation for " <<  totalTime << "s ..." << std::endl;

	SimulationUtils simProgress(progressInterval);
	simProgress.Start(totalTime);

	Simulator::Stop(Seconds(totalTime));
	Simulator::Run();

	std::cout << "Simulation Done!" << std::endl;
	ExportGraph();

	Simulator::Destroy();
}