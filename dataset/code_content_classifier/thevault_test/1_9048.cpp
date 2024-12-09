antlrcpp::Any QueryParser::visitOffsetClause(SPARQLParser::OffsetClauseContext *ctx)
{
	query_tree_ptr->setOffset(stoi(getTextWithRange(ctx->children[1])));

	return antlrcpp::Any();
}