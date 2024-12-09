hb_subset_plan_t *
hb_subset_plan_create (hb_face_t           *face,
		       hb_subset_input_t   *input)
{
  hb_subset_plan_t *plan = hb_object_create<hb_subset_plan_t> ();

  plan->drop_hints = input->drop_hints;
  plan->drop_layout = input->drop_layout;
  plan->unicodes = hb_set_create();
  plan->glyphs.init();
  plan->source = hb_face_reference (face);
  plan->dest = hb_face_builder_create ();
  plan->codepoint_to_glyph = hb_map_create();
  plan->glyph_map = hb_map_create();
  plan->glyphset = _populate_gids_to_retain (face,
					     input->unicodes,
					     !plan->drop_layout,
					     plan->unicodes,
					     plan->codepoint_to_glyph,
					     &plan->glyphs);
  _create_old_gid_to_new_gid_map (plan->glyphs,
				  plan->glyph_map);

  return plan;
}