EdgeString::EdgeString(const GeometryFactory *newFactory):
	factory(newFactory),
	directedEdges(new vector<LineMergeDirectedEdge*>()),
	coordinates(NULL)
{
}