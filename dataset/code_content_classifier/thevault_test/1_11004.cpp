UNICHAR_ID WERD_RES::BothSpaces(UNICHAR_ID id1, UNICHAR_ID id2) {
  if (id1 == id2 && id1 == uch_set->unichar_to_id(" ")) {
    return id1;
  } else {
    return INVALID_UNICHAR_ID;
  }
}