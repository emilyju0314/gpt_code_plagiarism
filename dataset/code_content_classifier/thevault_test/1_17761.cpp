inline bool CollisionIndex::isInsideTile(const CollisionBoundaries& boundaries,
                                         const CollisionBoundaries& tileBoundaries) const {
    return boundaries[0] >= tileBoundaries[0] && boundaries[1] >= tileBoundaries[1] &&
           boundaries[2] < tileBoundaries[2] && boundaries[3] < tileBoundaries[3];
}