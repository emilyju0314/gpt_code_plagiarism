antlrcpp::Any QueryParser::visitFilter(SPARQLParser::FilterContext *ctx, \
	QueryTree::GroupPattern &group_pattern)
{
	if (ctx->constraint()->functionCall())
		throw runtime_error("[ERROR]	Function call currently not supported in filter.");

	group_pattern.addOneFilter();

	if (ctx->constraint()->brackettedexpression())
		buildFilterTree(ctx->constraint()->brackettedexpression()->expression()->conditionalOrexpression(), \
			NULL, group_pattern.getLastFilter().root, "conditionalOrexpression");
	else if (ctx->constraint()->builtInCall())
		buildFilterTree(ctx->constraint()->builtInCall(), NULL, \
			group_pattern.getLastFilter().root, "builtInCall");

	return antlrcpp::Any();
}