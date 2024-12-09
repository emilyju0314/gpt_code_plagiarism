void parse_TT_spaces(llparse::parsegrammar & parse_grammar, std::stringstream & ss_out)
{
	const unsigned int a_spc = llparse::hash("spc");
	while (parse_grammar.terminal == a_spc) {
		accept_terminal(parse_grammar, ss_out);
	}
}