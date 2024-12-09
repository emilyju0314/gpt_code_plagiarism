asr::GAABB3
BrlcadObject::compute_local_bbox() const
{
    if (!this->rtip)
	return asr::GAABB3(asr::GVector3(0, 0, 0), asr::GVector3(0, 0, 0));

    // const auto r = static_cast<asr::GScalar>(get_uncached_radius());
    if (this->rtip->needprep)
	rt_prep_parallel(this->rtip, 1);

    // point_t min;
    // VSET(min, m_params.get_required<double>("minX"), m_params.get_required<double>("minY"), m_params.get_required<double>("minZ"));
    // VMOVE(min, ap->a_uvec);
    // point_t max;
    // VMOVE(max, ap->a_vvec);
    // VSET(max, m_params.get_required<double>("maxX"), m_params.get_required<double>("maxY"), m_params.get_required<double>("maxZ"));

    // fprintf(output, "Local Bounding Box: (%f, %f, %f) , (%f, %f, %f)\n", V3ARGS(min), V3ARGS(max));
    // fflush(output);

    return asr::GAABB3(asr::GVector3(V3ARGS(min)), asr::GVector3(V3ARGS(max)));
    // return asr::GAABB3(asr::GVector3(-r), asr::GVector3(r));
}