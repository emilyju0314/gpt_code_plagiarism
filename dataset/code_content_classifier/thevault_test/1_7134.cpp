void Fl_Text_Display::redisplay_range(int startpos, int endpos) {
  IS_UTF8_ALIGNED2(buffer(), startpos)
  IS_UTF8_ALIGNED2(buffer(), endpos)
  
  if (damage_range1_start == -1 && damage_range1_end == -1) {
    damage_range1_start = startpos;
    damage_range1_end = endpos;
  } else if ((startpos >= damage_range1_start && startpos <= damage_range1_end) ||
             (endpos >= damage_range1_start && endpos <= damage_range1_end)) {
    damage_range1_start = min(damage_range1_start, startpos);
    damage_range1_end = max(damage_range1_end, endpos);
  } else if (damage_range2_start == -1 && damage_range2_end == -1) {
    damage_range2_start = startpos;
    damage_range2_end = endpos;
  } else {
    damage_range2_start = min(damage_range2_start, startpos);
    damage_range2_end = max(damage_range2_end, endpos);
  }
  damage(FL_DAMAGE_SCROLL);
}