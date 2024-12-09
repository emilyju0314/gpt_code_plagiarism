void CExplorerWnd::OnFolderParent()
{
	ASSERT(!list_.IsDesktop());
	list_.DisplayParentFolder();
}