void UpdateCheckStateIn(
      vtkGraph *dbView,
      vector<QTreeWidgetItem *> &items,
      vtkIdType vert,
      Qt::CheckState state)
{
  // If we are being unchecked then we want to examine
  // collections that link in, so that they will be unchecked.
  if (state!=Qt::Unchecked)
    {
    return;
    }

  vtkIntArray *edgeType
    = dynamic_cast<vtkIntArray *>(dbView->GetEdgeData()->GetAbstractArray(0));

  vtkInEdgeIterator *it=vtkInEdgeIterator::New();
  dbView->GetInEdges(vert,it);

  // Follow links in.
  while (it->HasNext())
    {
    vtkInEdgeType edge=it->Next();
    if (edgeType->GetValue(edge.Id)==SIL_EDGE_LINK)
      {
      UpdateCheckStateIn(dbView,items,edge.Source,state);

      QTreeWidgetItem *item=items[edge.Source];
      item->setData(0,Qt::CheckStateRole,state);

      #if defined vtkVisitDatabaseBridgeDEBUG
      cerr << "\tupdating in " << items[edge.Source]->text(0).toStdString();
      cerr << endl;
      #endif
      }
    }
  it->Delete();
}