AttList makeAttributeList(const TableColumns& columns) {
    AttList list;

    for (const string& column : *columns.columnIds.get()) {
        list.appendAttribute(column);
    }

    return list;
}