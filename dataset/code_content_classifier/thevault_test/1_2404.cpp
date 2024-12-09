std::map<std::string, std::set<unsigned>> RTT_Mesh_Reader::get_element_sets() const {
  std::map<string, set_uint> element_sets;
  string flag_types_and_names;

  // loop over the number of side flag types.
  for (size_t type = 0; type < rttMesh->get_dims_nside_flag_types(); type++) {
    // loop over the number of side flags for this type.
    for (size_t flag = 0; flag < rttMesh->get_dims_nside_flags(type); flag++) {
      set_uint side_flags;
      flag_types_and_names = rttMesh->get_side_flags_flag_type(type);
      flag_types_and_names.append("/");
      flag_types_and_names += rttMesh->get_side_flags_flag_name(type, flag);
      unsigned flag_number = rttMesh->get_side_flags_flag_number(type, flag);
      // loop over the sides.
      for (unsigned side = 0; side < rttMesh->get_dims_nsides(); side++) {
        if (flag_number == rttMesh->get_sides_flags(side, type))
          side_flags.insert(side);
      }
      element_sets.insert(std::make_pair(flag_types_and_names, side_flags));
    }
  }

  size_t const nsides = rttMesh->get_dims_nsides();
  // loop over the number of cell flag types.
  for (size_t type = 0; type < rttMesh->get_dims_ncell_flag_types(); type++) {
    // loop over the number of cell flags for this type.
    for (size_t flag = 0; flag < rttMesh->get_dims_ncell_flags(type); flag++) {
      set_uint cell_flags;
      flag_types_and_names = rttMesh->get_cell_flags_flag_type(type);
      flag_types_and_names.append("/");
      flag_types_and_names += rttMesh->get_cell_flags_flag_name(type, flag);
      int flag_number = rttMesh->get_cell_flags_flag_number(type, flag);
      // loop over the cells.
      for (size_t cell = 0; cell < rttMesh->get_dims_ncells(); cell++) {
        if (flag_number == rttMesh->get_cells_flags(cell, type)) {
          Check(cell + nsides < UINT_MAX);
          cell_flags.insert(static_cast<unsigned>(cell + nsides));
        }
      }
      // Allow the possibility that the cells could have identical flags as the sides.
      if (element_sets.count(flag_types_and_names) != 0) {
        set_uint side_set = element_sets.find(flag_types_and_names)->second;
        for (auto side : side_set)
          cell_flags.insert(side);
        element_sets.erase(flag_types_and_names);
      }
      element_sets.insert(std::make_pair(flag_types_and_names, cell_flags));
    }
  }

  return element_sets;
}