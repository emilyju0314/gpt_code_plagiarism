void parse_template(llparse::parsegrammar &parse_grammar, std::stringstream &ss_out)
{
	const unsigned int a_tstart = llparse::hash("tstart");
	const unsigned int a_lcb = llparse::hash("lcb");
	const unsigned int a_esc = llparse::hash("esc");
	const unsigned int a_rcb = llparse::hash("rcb");
	const unsigned int a_word = llparse::hash("word");
	const unsigned int a_next = llparse::hash("next");
	const unsigned int a_fi = llparse::hash("fi");
	const unsigned int a_elsif = llparse::hash("elsif");
	const unsigned int a_else = llparse::hash("else");
	std::stringstream ss_html;
	bool processedTT = false;

	accept_terminal(parse_grammar, ss_html);
	while (!processedTT) {
		while (parse_grammar.terminal != parse_grammar.eos_sym &&
			parse_grammar.terminal != a_esc &&
			parse_grammar.terminal != a_lcb) {
			accept_terminal(parse_grammar, ss_html);
		}
		if (parse_grammar.terminal == parse_grammar.eos_sym) {
			ss_out << ss_html.str();
			return; // done
		}

		// Process the Template syntax 
		if (parse_grammar.terminal == a_lcb) {
			ss_out << ss_html.str();
			parse_lcb_TTBody_rcb(parse_grammar, ss_out);
			processedTT = true;
		}
		else {
			accept_terminal(parse_grammar, ss_html); // get esc
			accept_terminal(parse_grammar, ss_html); // get escaped char
		}
	}
	if (parse_grammar.terminal == a_next ||
		parse_grammar.terminal == a_fi ||
		parse_grammar.terminal == a_else ||
		parse_grammar.terminal == a_elsif) {
		return;
	}
	parse_template(parse_grammar, ss_out);

}