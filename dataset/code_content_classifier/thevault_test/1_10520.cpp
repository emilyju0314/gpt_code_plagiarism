SVMenuNode *Tesseract::build_menu_new() {
  SVMenuNode *parent_menu;
  auto *root_menu_item = new SVMenuNode();

  SVMenuNode *modes_menu_item = root_menu_item->AddChild("MODES");

  modes_menu_item->AddChild("Change Display", CHANGE_DISP_CMD_EVENT);
  modes_menu_item->AddChild("Dump Word", DUMP_WERD_CMD_EVENT);
  modes_menu_item->AddChild("Show Point", SHOW_POINT_CMD_EVENT);
  modes_menu_item->AddChild("Show BL Norm Word", SHOW_BLN_WERD_CMD_EVENT);
  modes_menu_item->AddChild("Config Words", DEBUG_WERD_CMD_EVENT);
  modes_menu_item->AddChild("Recog Words", RECOG_WERDS);
  modes_menu_item->AddChild("Recog Blobs", RECOG_PSEUDO);
  modes_menu_item->AddChild("Show Blob Features", SHOW_BLOB_FEATURES);

  parent_menu = root_menu_item->AddChild("DISPLAY");

  parent_menu->AddChild("Blamer", BLAMER_CMD_EVENT, false);
  parent_menu->AddChild("Bounding Boxes", BOUNDING_BOX_CMD_EVENT, false);
  parent_menu->AddChild("Correct Text", CORRECT_TEXT_CMD_EVENT, false);
  parent_menu->AddChild("Polygonal Approx", POLYGONAL_CMD_EVENT, false);
  parent_menu->AddChild("Baseline Normalized", BL_NORM_CMD_EVENT, false);
  parent_menu->AddChild("Edge Steps", BITMAP_CMD_EVENT, true);
  parent_menu->AddChild("Subscripts", SHOW_SUBSCRIPT_CMD_EVENT);
  parent_menu->AddChild("Superscripts", SHOW_SUPERSCRIPT_CMD_EVENT);
  parent_menu->AddChild("Italics", SHOW_ITALIC_CMD_EVENT);
  parent_menu->AddChild("Bold", SHOW_BOLD_CMD_EVENT);
  parent_menu->AddChild("Underline", SHOW_UNDERLINE_CMD_EVENT);
  parent_menu->AddChild("FixedPitch", SHOW_FIXEDPITCH_CMD_EVENT);
  parent_menu->AddChild("Serifs", SHOW_SERIF_CMD_EVENT);
  parent_menu->AddChild("SmallCaps", SHOW_SMALLCAPS_CMD_EVENT);
  parent_menu->AddChild("DropCaps", SHOW_DROPCAPS_CMD_EVENT);

  parent_menu = root_menu_item->AddChild("OTHER");

  parent_menu->AddChild("Quit", QUIT_CMD_EVENT);
  parent_menu->AddChild("Show Image", IMAGE_CMD_EVENT, false);
  parent_menu->AddChild("ShowBlock Outlines", BLOCKS_CMD_EVENT, false);
  parent_menu->AddChild("Show Baselines", BASELINES_CMD_EVENT, false);
  parent_menu->AddChild("Uniform Display", UNIFORM_DISP_CMD_EVENT);
  parent_menu->AddChild("Refresh Display", REFRESH_CMD_EVENT);

  return root_menu_item;
}