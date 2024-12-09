antlrcpp::Any QueryParser::visitSelectquery(SPARQLParser::SelectqueryContext *ctx)
{
	visit(ctx->selectClause());

	// datasetClause not supported

	// Call explictly to pass group_pattern as a parameter
	visitWhereClause(ctx->whereClause(), query_tree_ptr->getGroupPattern());

	visit(ctx->solutionModifier());

	return antlrcpp::Any();
}