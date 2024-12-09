TexturePatchCandidate
generate_candidate(int label, TextureView const & texture_view,
    std::vector<std::size_t> const & faces, mve::TriangleMesh::ConstPtr mesh,
    Settings const & settings) {

    mve::ByteImage::Ptr view_image = texture_view.get_image();
    int min_x = view_image->width(), min_y = view_image->height();
    int max_x = 0, max_y = 0;

    mve::TriangleMesh::FaceList const & mesh_faces = mesh->get_faces();
    mve::TriangleMesh::VertexList const & vertices = mesh->get_vertices();

    std::vector<math::Vec2f> texcoords;
    for (std::size_t i = 0; i < faces.size(); ++i) {
        for (std::size_t j = 0; j < 3; ++j) {
            math::Vec3f vertex = vertices[mesh_faces[faces[i] * 3 + j]];
            math::Vec2f pixel = texture_view.get_pixel_coords(vertex);

            texcoords.push_back(pixel);

            min_x = std::min(static_cast<int>(std::floor(pixel[0])), min_x);
            min_y = std::min(static_cast<int>(std::floor(pixel[1])), min_y);
            max_x = std::max(static_cast<int>(std::ceil(pixel[0])), max_x);
            max_y = std::max(static_cast<int>(std::ceil(pixel[1])), max_y);
        }
    }

    /* Check for valid projections/erroneous labeling files. */
    assert(min_x >= 0);
    assert(min_y >= 0);
    assert(max_x < view_image->width());
    assert(max_y < view_image->height());

    int width = max_x - min_x + 1;
    int height = max_y - min_y + 1;

    /* Add border and adjust min accordingly. */
    width += 2 * texture_patch_border;
    height += 2 * texture_patch_border;
    min_x -= texture_patch_border;
    min_y -= texture_patch_border;

    /* Calculate the relative texcoords. */
    math::Vec2f min(min_x, min_y);
    for (std::size_t i = 0; i < texcoords.size(); ++i) {
        texcoords[i] = texcoords[i] - min;
    }

    mve::ByteImage::Ptr byte_image;
    byte_image = mve::image::crop(view_image, width, height, min_x, min_y, *math::Vec3uc(255, 0, 255));
    mve::FloatImage::Ptr image = mve::image::byte_to_float_image(byte_image);

    if (settings.tone_mapping == TONE_MAPPING_GAMMA) {
        mve::image::gamma_correct(image, 2.2f);
    }

    TexturePatchCandidate texture_patch_candidate =
        {Rect<int>(min_x, min_y, max_x, max_y),
            TexturePatch::create(label, faces, texcoords, image)};
    return texture_patch_candidate;
}