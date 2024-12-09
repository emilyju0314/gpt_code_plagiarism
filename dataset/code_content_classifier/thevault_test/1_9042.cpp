void QueryParser::printTree(antlr4::tree::ParseTree *root, int dep)
{
	// Print tabs according to node's depth in tree
	for (int i = 0; i < dep; i++)
		cout << '-';

	string nodeTypeName = typeid(*root).name();
	size_t n = root->children.size();
	cout << "Type: " << nodeTypeName << ' ';
	cout << "Text: " << root->getText() << ' ';
	cout << "#Children: " << n << endl;

	for (size_t i = 0; i < n; i++)
	{
		antlr4::tree::ParseTree *childNode = root->children[i];
		printTree(childNode, dep + 1);
	}
}