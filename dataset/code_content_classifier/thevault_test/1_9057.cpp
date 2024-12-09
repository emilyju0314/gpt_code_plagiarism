antlrcpp::Any QueryParser::visitModify(SPARQLParser::ModifyContext *ctx)
{
	// ( 'WITH' iri )? not supported

	if (ctx->deleteClause() && ctx->insertClause())
	{
		query_tree_ptr->setUpdateType(QueryTree::Modify_Clause);
		visit(ctx->deleteClause());
		visit(ctx->insertClause());
	}
	else if (ctx->deleteClause())
	{
		query_tree_ptr->setUpdateType(QueryTree::Delete_Clause);
		visit(ctx->deleteClause());
	}
	else if (ctx->insertClause())
	{
		query_tree_ptr->setUpdateType(QueryTree::Insert_Clause);
		visit(ctx->insertClause());
	}

	// usingClause not supported

	visitGroupGraphPattern(ctx->groupGraphPattern(), query_tree_ptr->getGroupPattern());

	return antlrcpp::Any();
}