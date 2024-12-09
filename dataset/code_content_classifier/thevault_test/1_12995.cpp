void tst_QFavoriteServicesModel::modelTest()
{
    QtopiaServiceDescription a(QtopiaServiceDescription(QtopiaServiceRequest("a","a"),"a","a2"));
    QtopiaServiceDescription b(QtopiaServiceDescription(QtopiaServiceRequest("b","b"),"b","b2"));
    QFavoriteServicesModel model;
    model.insert(QModelIndex(),a);
    model.insert(QModelIndex(),b);
    QSpeedDial::set("1",a);

    QCOMPARE(model.rowCount(),2);
    QCOMPARE(model.description(model.index(0)),a);
    QCOMPARE(model.indexOf(a).row(),0);
    QCOMPARE(model.data(model.index(0),Qt::DisplayRole).toString(),QString("a"));
    QCOMPARE(model.description(model.index(1)),b);
    QCOMPARE(model.indexOf(b).row(),1);
    QCOMPARE(model.data(model.index(1),Qt::DisplayRole).toString(),QString("b"));
    QCOMPARE(model.speedDialInput(model.index(0)),QString("1"));
    QCOMPARE(model.data(model.index(0),QFavoriteServicesModel::SpeedDialInputRole).toString(),QString("1"));
    QCOMPARE(model.data(model.index(1),QFavoriteServicesModel::SpeedDialInputRole).toString(),QString(""));
}