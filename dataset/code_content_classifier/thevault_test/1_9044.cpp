antlrcpp::Any QueryParser::visitQuery(SPARQLParser::QueryContext *ctx)
{
	// printNode(ctx, "query");

	visit(ctx->prologue());

	// Only one of the following children is valid
	if (ctx->selectquery())
	{
		query_tree_ptr->setQueryForm(QueryTree::Select_Query);
		visit(ctx->selectquery());
	}
	if (ctx->constructquery())	// Not supported?
		visit(ctx->constructquery());
	if (ctx->describequery())	// Not supported?
		visit(ctx->describequery());
	if (ctx->askquery())
	{
		query_tree_ptr->setQueryForm(QueryTree::Ask_Query);
		visit(ctx->askquery());
	}

	visit(ctx->valuesClause());

	return antlrcpp::Any();
}