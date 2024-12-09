void tst_QFavoriteServicesModel::initTestCase()
{
    //It starts with the 1: Call VoiceMail which is default.
    QFavoriteServicesModel model;
    model.remove(model.index(0));
    QVERIFY(!model.rowCount());
}