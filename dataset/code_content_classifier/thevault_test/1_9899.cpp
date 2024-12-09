void UpdateCheckStateOut(
      vtkGraph *dbView,
      vector<QTreeWidgetItem *> &items,
      vtkIdType vert,
      Qt::CheckState state)
{
  vtkIntArray *edgeType
    = dynamic_cast<vtkIntArray *>(dbView->GetEdgeData()->GetAbstractArray(0));

  vtkOutEdgeIterator *it=vtkOutEdgeIterator::New();
  dbView->GetOutEdges(vert,it);

  // Follow links out.
  while (it->HasNext())
    {
    vtkOutEdgeType edge=it->Next();
    if (edgeType->GetValue(edge.Id)==SIL_EDGE_LINK)
      {
      UpdateCheckStateOut(dbView,items,edge.Target,state);

      QTreeWidgetItem *item=items[edge.Target];
      item->setData(0,Qt::CheckStateRole,state);

      #if defined vtkVisitDatabaseBridgeDEBUG
      cerr << "\tupdating out" << items[edge.Target]->text(0).toStdString();
      cerr << endl;
      #endif
      }
    }
  it->Delete();
}