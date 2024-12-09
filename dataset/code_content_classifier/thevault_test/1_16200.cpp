void parse_TT_write(llparse::parsegrammar & parse_grammar, std::stringstream & ss_out)
{
	const unsigned int a_rcb = llparse::hash("rcb");
	const unsigned int a_sqt = llparse::hash("sqt");
	const unsigned int a_dqt = llparse::hash("dqt");
	const unsigned int a_word = llparse::hash("word");
	const unsigned int a_num = llparse::hash("num");

	accept_terminal(parse_grammar, ss_out);
	parse_TT_spaces(parse_grammar, ss_out);
	// Double quotes for a literal value
	if (parse_grammar.terminal == a_dqt) {
		parse_TT_literal(parse_grammar, ss_out, a_dqt);
	}
	else if (parse_grammar.terminal == a_sqt) {
		parse_TT_literal(parse_grammar, ss_out, a_sqt);
	}
	else if (parse_grammar.terminal == a_word) {
		parse_TT_variable(parse_grammar, ss_out);
	}
	else if (parse_grammar.terminal == a_num) {
		accept_terminal(parse_grammar, ss_out);
	}
}