std::vector<std::pair<glm::vec3, glm::vec3> > Lens::imagePlanarGridPoints1D(float z, float dist_pts, int halfN) const
{
    std::vector<std::pair<glm::vec3, glm::vec3>> grid_point_mapping;

    for(int i = -halfN; i <= halfN; i++) {
        glm::vec3 pt(0.0f, i * dist_pts, z);
        glm::vec3 ptImg;
        imagePoint(glm::vec4(pt, 1.0), ptImg);
        grid_point_mapping.push_back(std::make_pair(pt, ptImg));
    }
    return grid_point_mapping;
}