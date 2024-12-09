void tiramisu::computation::store_in(buffer *buff)
{
    DEBUG_FCT_NAME(3);
    DEBUG_INDENT(4);

    assert(buff != NULL);

    isl_space *sp = isl_set_get_space(this->get_iteration_domain());
    isl_map *map = isl_map_identity(isl_space_map_from_set(sp));
    map = isl_map_set_tuple_name(map, isl_dim_out, buff->get_name().c_str());
    map = isl_map_coalesce(map);

    DEBUG(3, tiramisu::str_dump("Binding. The following access function is set: ",
                                isl_map_to_str(map)));

    this->set_access(isl_map_to_str(map));

    isl_map_free(map);

    DEBUG_INDENT(-4);
}