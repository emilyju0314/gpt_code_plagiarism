static std::pair<Required, std::vector<Option>> create_pattern_tree(std::string const& doc)
{
	auto usage_sections = parse_section("uso:", doc);
	if (usage_sections.empty()) {
		throw DocoptLanguageError("'uso:' (en mayúsculas o minúsculas) no encontrado.");
	}
	if (usage_sections.size() > 1) {
		throw DocoptLanguageError("Más de un 'uso:' (en mayúsculas o minúsculas).");
	}

	std::vector<Option> options = parse_defaults(doc);
	Required pattern = parse_pattern(formal_usage(usage_sections[0]), options);

	std::vector<Option const*> pattern_options = flat_filter<Option const>(pattern);

	using UniqueOptions = std::unordered_set<Option const*, PatternHasher, PatternPointerEquality>;
	UniqueOptions const uniq_pattern_options { pattern_options.begin(), pattern_options.end() };

	// Fix up any "[options]" shortcuts with the actual option tree
	for(auto& options_shortcut : flat_filter<OptionsShortcut>(pattern)) {
		std::vector<Option> doc_options = parse_defaults(doc);

		// set(doc_options) - set(pattern_options)
		UniqueOptions uniq_doc_options;
		for(auto const& opt : doc_options) {
			if (uniq_pattern_options.count(&opt))
				continue;
			uniq_doc_options.insert(&opt);
		}

		// turn into shared_ptr's and set as children
		PatternList children;
		std::transform(uniq_doc_options.begin(), uniq_doc_options.end(),
			       std::back_inserter(children), [](Option const* opt) {
				       return std::make_shared<Option>(*opt);
			       });
		options_shortcut->setChildren(std::move(children));
	}

	return { std::move(pattern), std::move(options) };
}