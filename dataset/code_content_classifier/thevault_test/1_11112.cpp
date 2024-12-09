static void RemoveBadBox(BLOBNBOX *box, ColPartition *part,
                         ColPartition_LIST *part_list) {
  part->RemoveBox(box);
  ColPartition::MakeBigPartition(box, part_list);
}