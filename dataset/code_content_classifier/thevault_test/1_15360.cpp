AttList makeAttributeList(const vector<TableColumn>& columns) {
    AttList list;

    for (const TableColumn& column : columns) {
        list.appendAttribute(column.columnId);
    }

    return list;
}