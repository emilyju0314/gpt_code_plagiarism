PathMode FromProc() {
	std::string abspath;
	abspath.resize(PATH_MAX);

	// get executable path from /proc/self/exe
	ssize_t size = readlink("/proc/self/exe", const_cast<char*>(abspath.c_str()), abspath.size());
	if ( size <= 0 ) {
		std::cerr << "Error could not evaluate absolute path from /proc/self/exe" << std::endl;
		std::cerr << "Failed with " << std::strerror(errno) << std::endl;
		std::exit(1);
	} // if

	// Trim extra characters
	abspath.resize(size);

	// Are we installed
	if ( abspath.rfind(CFA_BINDIR, 0) == 0 ) { return Installed; }

	// Is this the build tree
	if ( abspath.rfind(TOP_BUILDDIR, 0 ) == 0 ) { return BuildTree; }

	// Does this look like distcc
	if ( abspath.find( "/.cfadistcc/" ) != std::string::npos ) { return Distributed; }

	// None of the above? Give up since we don't know where the prelude or include directories are
	std::cerr << "Cannot find required files from excutable path " << abspath << std::endl;
	std::exit(1);
}