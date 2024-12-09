std::string flatcc_reference_var(size_t indent, std::string argument_name) {
	return emit("__$(INDENT)_$(ARGUMENT_NAME)", {
		{"$(INDENT)", std::to_string(indent)},
		{"$(ARGUMENT_NAME)", argument_name}
	});
}