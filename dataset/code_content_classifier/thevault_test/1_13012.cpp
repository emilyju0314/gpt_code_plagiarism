static void sampleListAppend(QQmlListProperty<SampleData> *prop, SampleData *val)
{
    SampleListModelPrivate *d = static_cast<SampleListModelPrivate*>(prop->data);
    d->sampleListData.append(val);
}