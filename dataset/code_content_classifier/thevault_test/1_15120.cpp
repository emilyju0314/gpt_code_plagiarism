static void ValidateEdgepoints()
{
	SOLDIERTYPE s;
	s = SOLDIERTYPE{};
	s.bTeam = ENEMY_TEAM;

	ValidateMapEdge(s, gus1stNorthEdgepointMiddleIndex, gps1stNorthEdgepointArray);
	ValidateMapEdge(s, gus1stEastEdgepointMiddleIndex,  gps1stEastEdgepointArray);
	ValidateMapEdge(s, gus1stSouthEdgepointMiddleIndex, gps1stSouthEdgepointArray);
	ValidateMapEdge(s, gus1stWestEdgepointMiddleIndex,  gps1stWestEdgepointArray);

	ValidateMapEdge(s, gus2ndNorthEdgepointMiddleIndex, gps2ndNorthEdgepointArray);
	ValidateMapEdge(s, gus2ndEastEdgepointMiddleIndex,  gps2ndEastEdgepointArray);
	ValidateMapEdge(s, gus2ndSouthEdgepointMiddleIndex, gps2ndSouthEdgepointArray);
	ValidateMapEdge(s, gus2ndWestEdgepointMiddleIndex,  gps2ndWestEdgepointArray);
}