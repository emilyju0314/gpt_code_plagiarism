void
BrlcadObject::intersect(
    const asr::ShadingRay& ray,
    IntersectionResult& result) const
{
    struct application app;
    app = ap;  /*struct copy*/
    /* brlcad raytracing */
    int cpu = get_id();
    app.a_resource = &resources[cpu];

    const asf::Vector3d dir = asf::normalize(ray.m_dir);
    VSET(app.a_ray.r_dir, dir[0], dir[1], dir[2]);
    VSET(app.a_ray.r_pt, ray.m_org[0], ray.m_org[1], ray.m_org[2]);

    app.a_uptr = (void*)this->name->c_str();

    if (rt_shootray(&app) == 0) {
	result.m_hit = false;
	return;
    } else {
	result.m_hit = true;
	result.m_distance = brlcad_ray_info.distance;

	const asf::Vector3d n = asf::normalize(brlcad_ray_info.normal);
	result.m_geometric_normal = n;

	// const asf::Vector3d n_flip (n[0], n[2], n[1]);
	// double temp;
	// temp = n_flip[2];
	// n_flip.set(2) = n_flip[1];
	// n_flip.set(1) = temp;
	result.m_shading_normal = n;

	// const asf::Vector3f p(brlcad_ray_info.normal * m_rcp_radius);
	// result.m_uv[0] = std::acos(p.y) * asf::RcpPi<float>();
	// result.m_uv[1] = std::atan2(-p.z, p.x) * asf::RcpTwoPi<float>();
	result.m_uv[0] = 1.0;
	result.m_uv[1] = 1.0;

	result.m_material_slot = 0;
    }
}