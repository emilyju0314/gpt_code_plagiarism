void Session::col_name(col_count_t pos,
                       const string &name, const string &original)
{
  if (m_discard)
    return;

  Col_metadata &md= (*m_col_metadata)[pos];

  md.m_name= name;
  md.m_name_original = original;
  md.m_has_name_original= true;
}