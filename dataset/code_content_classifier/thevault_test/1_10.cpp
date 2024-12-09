void
BrlcadObject::refine_and_offset(
    const asf::Ray3d& obj_inst_ray,
    asf::Vector3d& obj_inst_front_point,
    asf::Vector3d& obj_inst_back_point,
    asf::Vector3d& obj_inst_geo_normal) const
{
    obj_inst_front_point = obj_inst_ray.m_org;
    obj_inst_back_point = obj_inst_ray.m_org;
    obj_inst_geo_normal = -obj_inst_ray.m_dir;
}