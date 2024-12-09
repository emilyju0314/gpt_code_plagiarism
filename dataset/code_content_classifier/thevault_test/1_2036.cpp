void trace::MemoryTraceAnalyzer::application_list(bool filter) {
	using namespace ir;
	using namespace std;

	ApplicationMap applications = GetApplications(_kernels, filter);

	cout << "--\nKernels grouped by application:\n";

	// list kernels by application
	for (ApplicationMap::iterator fi = applications.begin(); 
		fi != applications.end(); ++fi) {
		cout << "\nApplication: '" << fi->second.name << "' with " 
			<< fi->second.kernels.size() << " kernels\n";
		for (int j = 0; j < (int)fi->second.kernels.size(); j++) {
			cout << "  kernel " << fi->second.kernels[j].kernel.name << hex
				<< " - 0x" << fi->second.kernels[j].header.global_min_address 
				<< " : 0x" << fi->second.kernels[j].header.global_max_address 
				<< dec << "\n";
		}
	}
	cout << "\n";
}