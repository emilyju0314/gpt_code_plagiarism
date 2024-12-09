bool Chunk::checkFace(int x, int y, int z) {

    if (x < 0 || x > 15 || y < 0 || y > 255 || z < 0 || z > 15) {
        return false;
    }

    return (blocks[x][y][z] == BlockType::AIR);
}