bool UNICHARSET::SizesDistinct(UNICHAR_ID id1, UNICHAR_ID id2) const {
  int overlap = std::min(unichars[id1].properties.max_top,
                         unichars[id2].properties.max_top) -
                std::max(unichars[id1].properties.min_top,
                         unichars[id2].properties.min_top);
  return overlap <= 0;
}