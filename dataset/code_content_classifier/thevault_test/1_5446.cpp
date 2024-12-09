isl_map *isl_map_filter_bmap_by_dupliate_ID(int ID, isl_map *map)
{
    DEBUG_FCT_NAME(3);
    DEBUG_INDENT(4);

    isl_map *identity = isl_map_universe(isl_map_get_space(map));
    identity = isl_set_identity(isl_map_range(isl_map_copy(map)));
    DEBUG(3, tiramisu::str_dump("Identity created from the range of the map: ",
                                isl_map_to_str(identity)));

    identity = isl_map_set_const_dim(identity, 0, ID);

    return isl_map_apply_range(isl_map_copy(map), identity);

    DEBUG_INDENT(-4);
}