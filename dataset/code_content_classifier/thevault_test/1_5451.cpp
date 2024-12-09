isl_map *tiramisu::computation::get_trimmed_union_of_schedules() const
{
    isl_map *trimmed_sched = isl_map_copy(this->get_schedule());
    const char *name = isl_map_get_tuple_name(this->get_schedule(), isl_dim_out);
    trimmed_sched = isl_map_project_out(trimmed_sched, isl_dim_out, 0, 1);
    trimmed_sched = isl_map_set_tuple_name(trimmed_sched, isl_dim_out, name);

    return trimmed_sched;
}