bool Chunk::checkNeighbour(int x, int y, int z) {

    // right
    if (x > 15 && !neighbours[0].isEmpty()) 
        return neighbours[0].getBlockWorldPos(Coordinates(0, y, z)) == BlockType::AIR;

    // left
    if (x < 0 && !neighbours[1].isEmpty()) 
        return neighbours[1].getBlockWorldPos(Coordinates(15, y, z)) == BlockType::AIR;

    // front
    if (z > 15 && !neighbours[2].isEmpty()) 
        return neighbours[2].getBlockWorldPos(Coordinates(x, y, 0)) == BlockType::AIR;

    // back
    if (z < 0 && !neighbours[3].isEmpty()) 
        return neighbours[3].getBlockWorldPos(Coordinates(x, y, 15)) == BlockType::AIR;

    if (x < 0 || x > 15 || y < 0 || y > 255 || z < 0 || z > 15) {
        return false;
    }
    return (blocks[x][y][z] == BlockType::AIR || blocks[x][y][z] == BlockType::LEAVES || checkPlants(blocks[x][y][z]));
}