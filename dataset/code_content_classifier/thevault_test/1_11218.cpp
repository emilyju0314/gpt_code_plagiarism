void UNICHARSET::set_normed_ids(UNICHAR_ID unichar_id) {
  unichars[unichar_id].properties.normed_ids.clear();
  if (unichar_id == UNICHAR_SPACE && id_to_unichar(unichar_id)[0] == ' ') {
    unichars[unichar_id].properties.normed_ids.push_back(UNICHAR_SPACE);
  } else if (!encode_string(unichars[unichar_id].properties.normed.c_str(),
                            true, &unichars[unichar_id].properties.normed_ids,
                            nullptr, nullptr)) {
    unichars[unichar_id].properties.normed_ids.clear();
    unichars[unichar_id].properties.normed_ids.push_back(unichar_id);
  }
}