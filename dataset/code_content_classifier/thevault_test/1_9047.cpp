antlrcpp::Any QueryParser::visitLimitClause(SPARQLParser::LimitClauseContext *ctx)
{
	query_tree_ptr->setLimit(stoi(getTextWithRange(ctx->children[1])));

	return antlrcpp::Any();
}