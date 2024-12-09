void QueryParser::printNode(antlr4::ParserRuleContext *ctx, 
	const char *nodeTypeName)
{
	int dep = ctx->depth();

	// Print tabs according to node's depth in tree
	for (int i = 0; i < dep; i++)
		cout << '\t';

	// Print node type
	cout << "Type: " << nodeTypeName << ' ';

	// Print what text a node has matched
	cout << "Text: " << ctx->getText() << endl;

}