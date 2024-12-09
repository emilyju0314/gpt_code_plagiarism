void QueryParser::SPARQLParse(const string &query)
{
	istringstream ifs(query);

	SPARQLErrorListener lstnr;

	antlr4::ANTLRInputStream input(ifs);
	SPARQLLexer lexer(&input);
	lexer.removeErrorListeners();
	lexer.addErrorListener(&lstnr);

	antlr4::CommonTokenStream tokens(&lexer);
	SPARQLParser parser(&tokens);
	parser.removeErrorListeners();
	parser.addErrorListener(&lstnr);

	SPARQLParser::EntryContext *tree = parser.entry();
	// printTree(tree, 0);
	visitEntry(tree);
}