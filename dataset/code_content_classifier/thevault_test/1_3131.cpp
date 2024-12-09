void CGridCtrl::CutSelectedText()
{
    if (!IsEditable())
        return;

    CCellRange Selection = GetSelectedCellRange();
    if (!IsValid(Selection))
        return;

	ClearCells(Selection);
}