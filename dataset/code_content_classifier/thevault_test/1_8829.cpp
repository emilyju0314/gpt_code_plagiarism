bool is_block_insert(vi* vi)
{
  return vi->mode().is_insert() &&
         (vi->get_stc()->SelectionIsRectangle() ||
          vi->get_stc()->GetSelectionMode() == wxSTC_SEL_THIN);
}