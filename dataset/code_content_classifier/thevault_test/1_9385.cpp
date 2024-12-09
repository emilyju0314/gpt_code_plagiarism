void
BusTopology::InstallInternetStack()
{
	std::cout << "Installing Internet Stack" << std::endl;
	// Set static routing
	Ipv4StaticRoutingHelper staticRouting;

	Ipv4ListRoutingHelper list;
	list.Add (staticRouting, 10);

	InternetStackHelper internet;
	internet.SetRoutingHelper (list); // has effect on the next Install ()

	internet.Install (nodes);

	// Assign IP Addresses
	Ipv4AddressHelper addresses;
	addresses.SetBase ("10.0.0.0", "255.255.0.0");
	interfaces = addresses.Assign (devices);
}