QQmlListProperty<QObject> DataObjectModel::content()
{
    return QQmlListProperty<QObject>(this,
                                     0,
                                     &DataObjectModel::dataObjectAppend,
                                     &DataObjectModel::dataObjectCount,
                                     &DataObjectModel::dataObjectAt,
                                     &DataObjectModel::dataObjectClear);
}