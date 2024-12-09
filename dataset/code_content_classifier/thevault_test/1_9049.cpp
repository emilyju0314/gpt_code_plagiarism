antlrcpp::Any QueryParser::visitGroupGraphPattern(SPARQLParser::GroupGraphPatternContext *ctx, \
	QueryTree::GroupPattern &group_pattern)
{
	// subSelect not supported

	visitGroupGraphPatternSub(ctx->groupGraphPatternSub(), group_pattern);

	return antlrcpp::Any(); 
}