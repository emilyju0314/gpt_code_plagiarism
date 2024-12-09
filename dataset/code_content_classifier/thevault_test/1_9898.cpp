void CopySIL(
      vtkGraph *dbView,
      vtkOutEdgeIterator * eit,
      QTreeWidgetItem *p,
      QTreeWidget *w,
      vector<QTreeWidgetItem *> &items)
{
  // Data for the view.
  // vert
  vtkStringArray *uiLabels
    = dynamic_cast<vtkStringArray *>(dbView->GetVertexData()->GetAbstractArray(0));
  vtkIntArray *ssIds
    = dynamic_cast<vtkIntArray *>(dbView->GetVertexData()->GetAbstractArray(1));
  vtkIntArray *ssRole
    = dynamic_cast<vtkIntArray *>(dbView->GetVertexData()->GetAbstractArray(2));
  // 
  vtkIntArray *edgeType
    = dynamic_cast<vtkIntArray *>(dbView->GetEdgeData()->GetAbstractArray(0));

  // Visit each vertex
  while (eit->HasNext())
    {
    vtkOutEdgeType edge=eit->Next();
    int vert=edge.Target;

    if (edgeType->GetValue(edge.Id)!=SIL_EDGE_STRUCTURAL)
      {
      // We have to skip over link edges.
      continue;
      }

    bool ok;
    // Use labels from the reader to identify entries in the 
    // Qtree.
    string uiLabel=uiLabels->GetValue(vert);
    QList<QString> label;
    label.append(uiLabel.c_str());

    QTreeWidgetItem *item;
    if (p)
      {
      // This is a branch (category) or leaf (SIL Set).
      item=new pqTreeWidgetItemObject(p,label);
      }
    else
      {
      // This is a top level item (mesh).
      item=new pqTreeWidgetItemObject(w,label);
      item->setData(0, Qt::DecorationRole, pixmaps[1]);
      // I'd like to make the check box on the mesh entries checkable
      // such that when clicked, all child domains,  all child 
      // assemblies and all child blocks are check/unchecked as well
      // and Checked/UnChecked/Partial state apply only to those branches
      // not to others such as arrays, expressions, or materials.
      }
    // Save the pointer to the widget for easy lookup. Want to store in the
    // database view but there is not mechanism for storing pointers.
    items[vert]=item;
    // Configure
    item->setFlags(item->flags() | Qt::ItemIsTristate);
    item->setChildIndicatorPolicy(QTreeWidgetItem::DontShowIndicatorWhenChildless);
    item->setCheckState(0,Qt::Unchecked);
    item->setExpanded(false);
    // Save the vertex id so that we can look up various data stored in the view.
    item->setData(0,QT_SS_VERT,QVariant(vert));

    // Follow the edges out.
    vtkOutEdgeIterator *childEit=vtkOutEdgeIterator::New();
    dbView->GetOutEdges(vert,childEit);
    CopySIL(dbView,childEit,item,w,items);
    childEit->Delete();
    }
  return;
}