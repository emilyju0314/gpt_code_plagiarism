void PasteStructure( UINT32 iMapIndex )
{
	pSelList = SelOStructs;
	pNumSelList = &iNumOStructsSelected;

	PasteStructureCommon( iMapIndex );
}