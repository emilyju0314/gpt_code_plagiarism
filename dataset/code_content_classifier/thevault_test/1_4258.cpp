clReturn oclGetInfo(cl_platform_id plid, cl_e_platform_info eInfo, std::string & val) {
	val.clear();
	size_t cb = 0;
	clReturn clr = ocl.GetPlatformInfo(plid, eInfo, g_cBuffer, g_buffer, &cb);
	if ((clr == CL_SUCCESS) && (g_cBuffer <= cb)) {
		if (g_buffer) free (g_buffer);
		if (cb < 120) cb = 120;
		g_buffer = (char*)malloc(cb*2);
		if ( ! g_buffer) { print_error(MODE_ERROR, "ERROR: failed to allocate %d bytes\n", (int)(cb*2)); exit(-1); }
		g_cBuffer = (unsigned int)(cb*2);
		clr = ocl.GetPlatformInfo(plid, eInfo, g_cBuffer, g_buffer, &cb);
	}
	if (clr == CL_SUCCESS) {
		g_buffer[g_cBuffer-1] = 0;
		val = g_buffer;
		if (ocl_log) { print_error(MODE_VERBOSE, "\t%s: \"%s\"\n", ocl_name(eInfo), val.c_str()); }
	}
	return clr;
}