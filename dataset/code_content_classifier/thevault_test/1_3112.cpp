void CGridCellCombo::SetOptions(CStringArray& ar)
{
    m_Strings.RemoveAll();
    for (int i = 0; i < ar.GetSize(); i++)
        m_Strings.Add(ar[i]);
}