inline void logTo(file& f, string_view msg) try {
	print(f, msg);
} catch (system_error const& e) {
	print(cerr, R"(Failed to write to logfile "{}": {}\n)", f.where(), e.what());
}