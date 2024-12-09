bool
BrlcadObject::intersect(const asr::ShadingRay& ray) const
{
    struct application app;
    app = ap; /* struct copy */
    /* brlcad raytracing */
    int cpu = get_id();
    app.a_resource = &resources[cpu];

    const asf::Vector3d dir = asf::normalize(ray.m_dir);
    VSET(app.a_ray.r_dir, dir[0], dir[1], dir[2]);
    VSET(app.a_ray.r_pt, ray.m_org[0], ray.m_org[1], ray.m_org[2]);

    return (rt_shootray(&app) == 1);
}