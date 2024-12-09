void addCrossFace_1(std::vector<GLfloat> &buffer_data, Coordinates coord, BlockType bt) {

    TextureSides ts = getTextureSides(bt);

     // texture isn't properly alligned so need to adjust it
    float texture_hack_fix = 0.01;
    // the side to decrease the face's width (don't want plants to be a block's width)
    float size = 0;
    if (bt == BlockType::MUSHROOM_RED) {
        size = 0.2;
    } else if (bt == BlockType::MUSHROOM_PINK) { // FLOWER_RED_PLANT && FLOWER_YELLOW_PLANT
        size = 0.1;
    } else if (bt == BlockType::FERN_1) { // FLOWER_RED_PLANT && FLOWER_YELLOW_PLANT
        size = 0.1;
    } else if (bt == BlockType::FERN_2) { // FLOWER_RED_PLANT && FLOWER_YELLOW_PLANT
        size = 0.1;
    } else if (bt == BlockType::FLOWER_YELLOW_PLANT) { // FLOWER_RED_PLANT && FLOWER_YELLOW_PLANT
        size = 0.1;
    } 

    GLfloat vert_uv_data[] = {
        // front side
        coord.x+size, coord.y, coord.z+size,   TEXCOORDX(ts.back_x)-texture_hack_fix,  TEXCOORDY(ts.back_y)-texture_hack_fix, 0, 0, 1,
        coord.x+size, coord.y+1.0f, coord.z+size,   TEXCOORDX(ts.back_x)-texture_hack_fix,  TEXCOORDY(ts.back_y)+N+texture_hack_fix,  0, 0, 1,
        coord.x+1.0f-size, coord.y, coord.z+1.0f-size,   TEXCOORDX(ts.back_x)+N+texture_hack_fix,TEXCOORDY(ts.back_y)-texture_hack_fix,  0, 0, 1,
        coord.x+1.0f-size, coord.y, coord.z+1.0f-size,   TEXCOORDX(ts.back_x)+N+texture_hack_fix,TEXCOORDY(ts.back_y)-texture_hack_fix,  0, 0, 1,
        coord.x+size, coord.y+1.0f, coord.z+size,   TEXCOORDX(ts.back_x)-texture_hack_fix,  TEXCOORDY(ts.back_y)+N+texture_hack_fix,  0, 0, 1,
        coord.x+1.0f-size, coord.y+1.0f, coord.z+1.0f-size,   TEXCOORDX(ts.back_x)+N+texture_hack_fix,TEXCOORDY(ts.back_y)+N+texture_hack_fix,  0, 0, 1,

        // back side
        coord.x+size, coord.y, coord.z+size,   TEXCOORDX(ts.front_x)+N+texture_hack_fix,TEXCOORDY(ts.front_y)-texture_hack_fix, 0, 0, 1,
        coord.x+1.0f-size, coord.y, coord.z+1.0f-size,   TEXCOORDX(ts.front_x)-texture_hack_fix,  TEXCOORDY(ts.front_y)-texture_hack_fix, 0, 0, 1,
        coord.x+size, coord.y+1.0f, coord.z+size,   TEXCOORDX(ts.front_x)+N+texture_hack_fix,TEXCOORDY(ts.front_y)+N+texture_hack_fix, 0, 0, 1,
        coord.x+1.0f-size, coord.y, coord.z+1.0f-size,   TEXCOORDX(ts.front_x)-texture_hack_fix,  TEXCOORDY(ts.front_y)-texture_hack_fix, 0, 0, 1,
        coord.x+1.0f-size, coord.y+1.0f, coord.z+1.0f-size,   TEXCOORDX(ts.front_x)-texture_hack_fix,  TEXCOORDY(ts.front_y)+N+texture_hack_fix, 0, 0, 1,
        coord.x+size, coord.y+1.0f, coord.z+size,   TEXCOORDX(ts.front_x)+N+texture_hack_fix,TEXCOORDY(ts.front_y)+N+texture_hack_fix, 0, 0, 1,
    };
    buffer_data.insert(buffer_data.end(), vert_uv_data, vert_uv_data+96);
}