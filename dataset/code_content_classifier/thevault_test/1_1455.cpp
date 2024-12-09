Node*
NodeMap::find(const Coordinate& coord) const
{
	Coordinate *c=const_cast<Coordinate *>(&coord);

	NodeMap::const_iterator found=nodeMap.find(c);

	if (found==nodeMap.end())
		return NULL;
	else
		return found->second;
}