bool TLevelWriterTzl::checkIconSize(const TDimension &newSize) {
  assert(m_version >= 13);

  if (!m_exists || m_iconOffsTable.empty() || !m_chan || m_version < 13)
    return false;

  // Read the size of icons in the file
  TINT32 iconLx = 0, iconLy = 0;

  long currentPos =
      ftell(m_chan);  // Backup current reading position in the file

  TzlOffsetMap::iterator it = m_iconOffsTable.begin();
  long offs                 = it->second.m_offs;

  fseek(m_chan, offs, SEEK_SET);

  fread(&iconLx, sizeof(TINT32), 1, m_chan);
  fread(&iconLy, sizeof(TINT32), 1, m_chan);

  fseek(m_chan, currentPos,
        SEEK_SET);  // Reset to the original position in the file

  assert(iconLx > 0 && iconLy > 0);
  if (iconLx <= 0 || iconLy <= 0 || iconLx > m_res.lx || iconLy > m_res.ly)
    return false;

  m_currentIconSize = TDimension(
      iconLx, iconLy);  // This is not performed if the above pre-emptive
                        // bailout kicks in. BTW, m_currentIconSize
                        // is currently UNUSED! Should be cleaned up...
  // Compare newSize against read icon size in the file
  return (m_currentIconSize == newSize);
}