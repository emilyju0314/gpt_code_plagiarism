antlrcpp::Any QueryParser::visitQueryUnit(SPARQLParser::QueryUnitContext *ctx)
{
	// printNode(ctx, "queryUnit");

	visit(ctx->query());

	return antlrcpp::Any();
}