antlrcpp::Any QueryParser::visitOptionalGraphPattern(SPARQLParser::OptionalGraphPatternContext *ctx, \
	QueryTree::GroupPattern &group_pattern)
{
	group_pattern.addOneOptional(QueryTree::GroupPattern::SubGroupPattern::Optional_type);
	visitGroupGraphPattern(ctx->groupGraphPattern(), group_pattern.getLastOptional());

	return antlrcpp::Any();
}