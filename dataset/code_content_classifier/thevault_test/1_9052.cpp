antlrcpp::Any QueryParser::visitMinusGraphPattern(SPARQLParser::MinusGraphPatternContext *ctx, \
	QueryTree::GroupPattern &group_pattern)
{
	group_pattern.addOneOptional(QueryTree::GroupPattern::SubGroupPattern::Minus_type);
	visitGroupGraphPattern(ctx->groupGraphPattern(), group_pattern.getLastOptional());

	return antlrcpp::Any();
}