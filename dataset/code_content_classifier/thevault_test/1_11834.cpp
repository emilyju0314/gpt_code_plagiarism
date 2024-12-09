void AddCommonNodePaletteUtilities(GraphCanvas::GraphCanvasTreeItem* rootItem, const GraphCanvas::EditorId& editorId)
    {
        GraphCanvas::IconDecoratedNodePaletteTreeItem* utilitiesCategory = rootItem->CreateChildNode<GraphCanvas::IconDecoratedNodePaletteTreeItem>("Utilities", editorId);
        utilitiesCategory->SetTitlePalette("UtilityNodeTitlePalette");
        utilitiesCategory->CreateChildNode<CommentNodePaletteTreeItem>("Comment", editorId);
        utilitiesCategory->CreateChildNode<NodeGroupNodePaletteTreeItem>("Node Group", editorId);
    }