void FreeLabeledClassList(LIST ClassList) {
  MERGE_CLASS MergeClass;

  LIST nodes = ClassList;
  iterate(ClassList) /* iterate through all of the fonts */
  {
    MergeClass = reinterpret_cast<MERGE_CLASS>(ClassList->first_node());
    FreeClass(MergeClass->Class);
    delete MergeClass;
  }
  destroy(nodes);

}