hb_face_t *
hb_subset (hb_face_t *source,
	   hb_subset_input_t *input)
{
  if (unlikely (!input || !source)) return hb_face_get_empty ();

  hb_subset_plan_t *plan = hb_subset_plan_create (source, input);

  hb_tag_t table_tags[32];
  unsigned int offset = 0, count;
  bool success = true;
  do {
    count = ARRAY_LENGTH (table_tags);
    hb_face_get_table_tags (source, offset, &count, table_tags);
    for (unsigned int i = 0; i < count; i++)
    {
      hb_tag_t tag = table_tags[i];
      if (_should_drop_table (plan, tag))
      {
	DEBUG_MSG(SUBSET, nullptr, "drop %c%c%c%c", HB_UNTAG (tag));
	continue;
      }
      success = success && _subset_table (plan, tag);
    }
    offset += count;
  } while (success && count == ARRAY_LENGTH (table_tags));

  hb_face_t *result = success ? hb_face_reference (plan->dest) : hb_face_get_empty ();
  hb_subset_plan_destroy (plan);
  return result;
}