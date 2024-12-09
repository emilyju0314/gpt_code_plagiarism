void displayTable(Table* pt) {
    const RecordDef* ps = pt->getSchema();
    for (int i = 0; i < pt->getNumRecords(); i++) {
        display(pt->getRecord(i), ps);
    }
}