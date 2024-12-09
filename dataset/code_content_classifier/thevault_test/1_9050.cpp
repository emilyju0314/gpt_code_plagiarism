antlrcpp::Any QueryParser::visitGroupOrUnionGraphPattern(SPARQLParser::GroupOrUnionGraphPatternContext *ctx, \
	QueryTree::GroupPattern &group_pattern)
{
	if (ctx->children.size() == 1)
	{
		group_pattern.addOneGroup();
		visitGroupGraphPattern(ctx->groupGraphPattern(0), group_pattern.getLastGroup());
	}
	else
	{
		group_pattern.addOneGroupUnion();
		for (auto groupGraphPattern : ctx->groupGraphPattern())
		{
			group_pattern.addOneUnion();
			visitGroupGraphPattern(groupGraphPattern, group_pattern.getLastUnion());
		}
	}

	return antlrcpp::Any();
}