inline bool load_scene(
    app_state* scn, const std::string& filename, bool instances, bool radius) {
    // load scene
    auto ext = ygl::path_extension(filename);
    try {
        scn->gscn = ygl::load_scenes(filename, true, true);
    } catch (const std::exception& e) {
        ygl::log_error(
            "cannot load scene {} with error {}", filename, e.what());
    }
    ygl::add_normals(scn->gscn);
    ygl::add_texture_data(scn->gscn);
    if (scn->add_spec_gloss) ygl::add_spec_gloss(scn->gscn);
    if (radius) ygl::add_radius(scn->gscn, 0.001f);
    ygl::add_tangent_space(scn->gscn);
    if (instances) {
        ygl::add_nodes(scn->gscn);
        ygl::add_scene(scn->gscn);
    }
    ygl::add_names(scn->gscn);
    scn->time_range = ygl::get_animation_bounds(scn->gscn);
    if (!scn->gscn->default_scene && !scn->gscn->scenes.empty()) {
        scn->gscn->default_scene = scn->gscn->scenes[0];
    }
    if (!ygl::get_camera_nodes(scn->gscn->default_scene).empty()) {
        auto cam = ygl::get_camera_nodes(scn->gscn->default_scene)[0];
        scn->view_cam = new camera();
        scn->view_cam->frame = ygl::to_frame3f(ygl::mat4f(cam->xform()));
        scn->view_cam->yfov = cam->cam->yfov;
        scn->view_cam->aspect = cam->cam->aspect;
        scn->view_cam->near = cam->cam->near;
        scn->view_cam->far = cam->cam->far;
        scn->view_cam->focus = cam->cam->focus;
        scn->view_cam->aperture = cam->cam->aperture;
    }

#if 1
    if (!scn->view_cam) {
        auto bbox = ygl::bbox3f{ygl::compute_scene_bounds(scn->gscn)};
        auto center = (bbox.max + bbox.min) / 2.0f;
        auto bbox_size = bbox.max - bbox.min;
        auto bbox_msize = length(bbox_size) / 2;
        // auto bbox_msize =
        //     ygl::max(bbox_size[0], ygl::max(bbox_size[1], bbox_size[2]));
        scn->view_cam = new camera();
        auto camera_dir = ygl::vec3f{1.5f, 0.8f, 1.5f};
        auto from = camera_dir * bbox_msize + center;
        auto to = center;
        auto up = ygl::vec3f{0, 1, 0};
        scn->view_cam->frame = ygl::lookat_frame3f(from, to, up);
        scn->view_cam->aspect = 16.0f / 9.0f;
        scn->view_cam->yfov = 2 * atanf(0.5f);
        scn->view_cam->aperture = 0;
        scn->view_cam->focus = ygl::length(to - from);
    }
#else
    if (!scn->view_cam) {
        auto bbox = (scn->oscn) ?
                        ygl::bbox3f{yobj::compute_scene_bounds(scn->oscn)} :
                        ygl::bbox3f{ygl::compute_scene_bounds(scn->gscn)};
        auto center = ygl::center(bbox);
        auto bbox_size = ygl::diagonal(bbox);
        scn->view_cam = new ycamera();
        auto from =
            center + ygl::vec3f{0, 0, 1} *
                         (bbox_size.z + ygl::max(bbox_size.x, bbox_size.y));
        auto to = center;
        auto up = ygl::vec3f{0, 1, 0};
        scn->view_cam->frame = ygl::lookat_frame3(from, to, up);
        scn->view_cam->aspect = 16.0f / 9.0f;
        scn->view_cam->yfov = 2 * atanf(0.5f);
        scn->view_cam->aperture = 0;
        scn->view_cam->focus = ygl::length(to - from);
    }
#endif
    return true;
}