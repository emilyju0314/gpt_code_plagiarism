void QueryParser::addTriple(string subject, string predicate, string object, \
	QueryTree::GroupPattern &group_pattern)
{
	// Add one pattern
	group_pattern.addOnePattern(QueryTree::GroupPattern::Pattern(QueryTree::GroupPattern::Pattern::Element(subject), \
		QueryTree::GroupPattern::Pattern::Element(predicate), \
		QueryTree::GroupPattern::Pattern::Element(object)));

	// Scope of filter
	for (int j = (int)group_pattern.sub_group_pattern.size() - 1; j > 0; j--)
	{
		if (group_pattern.sub_group_pattern[j].type == QueryTree::GroupPattern::SubGroupPattern::Pattern_type &&
			group_pattern.sub_group_pattern[j - 1].type == QueryTree::GroupPattern::SubGroupPattern::Filter_type)
		{
			QueryTree::GroupPattern::SubGroupPattern tmp(group_pattern.sub_group_pattern[j - 1]);
			group_pattern.sub_group_pattern[j - 1] = group_pattern.sub_group_pattern[j];
			group_pattern.sub_group_pattern[j] = tmp;
		}
		else
			break;
	}
}