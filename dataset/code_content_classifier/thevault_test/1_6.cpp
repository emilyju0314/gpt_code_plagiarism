BrlcadObject:: BrlcadObject(
    const char* name,
    const asr::ParamArray& params,
    struct application* p_ap, struct resource* p_resources)
    : asr::ProceduralObject(name, params)
{
    // this->rtip = p_ap->a_rt_i;
    this->resources = p_resources;
    // VMOVE(this->min, ap->a_uvec);
    // VMOVE(this->max, ap->a_vvec);

    this->name = new std::string(m_params.get_required<std::string>("object_path"));
    VSET(min, m_params.get_required<double>("minX"), m_params.get_required<double>("minY"), m_params.get_required<double>("minZ"));
    VSET(max, m_params.get_required<double>("maxX"), m_params.get_required<double>("maxY"), m_params.get_required<double>("maxZ"));

    std::string db_file = m_params.get_required<std::string>("database_path");
    this->rtip = rt_new_rti(p_ap->a_rt_i->rti_dbip);
    if (this->rtip == RTI_NULL) {
        RENDERER_LOG_INFO("building the database directory for [%s] FAILED\n", db_file.c_str());
        bu_exit(BRLCAD_ERROR, "building the database directory for [%s] FAILED\n", db_file.c_str());
    }

    for (int ic = 0; ic < MAX_PSW; ic++) {
	rt_init_resource(&p_resources[ic], ic, this->rtip);
        RT_CK_RESOURCE(&p_resources[ic]);
    }

    rt_gettree(this->rtip, this->name->c_str());
    if (this->rtip->needprep)
        rt_prep_parallel(this->rtip, 1);
    //printf("name: [%s]\n", name);
    //this->rtip = rt_dirbuild();
    //this->rtip = p_ap->a_rt_i;

    // VSETALL(ap->a_uvec, 0);
    // VSETALL(ap->a_vvec, 0);

    // fprintf(output, "art.cpp const: Local Bounding Box: (%f, %f, %f) , (%f, %f, %f)\n", V3ARGS(min), V3ARGS(max));
    // fflush(output);

    RT_APPLICATION_INIT(&ap);

    /* configure raytrace application */
    ap.a_rt_i = this->rtip;
    ap.a_onehit = 1;
    ap.a_hit = brlcad_hit;
    ap.a_miss = brlcad_miss;
}