BOOL CGridCtrl::OnDrop(COleDataObject* pDataObject, DROPEFFECT /*dropEffect*/,
                       CPoint /* point */)
{
    m_MouseMode = MOUSE_NOTHING;

    if (!m_bAllowDragAndDrop || !IsCellEditable(m_LastDragOverCell))
        return FALSE;

    OnDragLeave();

    return PasteTextToGrid(m_LastDragOverCell, pDataObject);
}