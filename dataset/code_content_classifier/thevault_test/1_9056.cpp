antlrcpp::Any QueryParser::visitDeleteData(SPARQLParser::DeleteDataContext *ctx)
{
	query_tree_ptr->setUpdateType(QueryTree::Delete_Data);

	visit(ctx->quadData());

	return antlrcpp::Any();
}