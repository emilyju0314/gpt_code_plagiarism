antlrcpp::Any QueryParser::visitAskquery(SPARQLParser::AskqueryContext *ctx)
{
	query_tree_ptr->setQueryForm(QueryTree::Ask_Query);
	query_tree_ptr->setProjectionAsterisk();

	// datasetClause not supported

	// Call explictly to pass group_pattern as a parameter
	visitWhereClause(ctx->whereClause(), query_tree_ptr->getGroupPattern());

	visit(ctx->solutionModifier());

	return antlrcpp::Any();
}