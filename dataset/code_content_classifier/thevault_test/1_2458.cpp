void RTT_Format_Reader::reformatData(vector_vector_uint const &cell_side_types,
                                     std::vector<vector_vector_uint> const &cell_ordered_sides) {
  spCellDefs->redefineCellDefs(cell_side_types, cell_ordered_sides);
  spSides->redefineSides();
  spCells->redefineCells();
}