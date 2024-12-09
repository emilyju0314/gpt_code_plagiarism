void tst_QFavoriteServicesModel::modifyTest()
{
    int numDescs=5;
    QtopiaServiceDescription test[numDescs];
    for(int i = 0; i<numDescs; i++){
        test[i] = QtopiaServiceDescription(QtopiaServiceRequest(QString("test%1").arg(i),
                        QString("test%1").arg(i)),QString("test%1").arg(i),
                        QString("test%1").arg(i));
    }
    QtopiaServiceDescription found;
    QFavoriteServicesModel model;

    for(int i = 0; i<100; i++){
        found = model.description(model.index(i));
        QVERIFY(found.isNull());
    }
    for(int i = 0; i<(100-numDescs); i++){
        model.insert(QModelIndex(),test[i%numDescs]);
    }
    QCOMPARE(model.rowCount(), numDescs);//Should not allow duplicates
    for(int i = 0; i<numDescs; i++){
        model.insert(model.index(i),test[i]);
    }
    for(int i = 0; i<numDescs; i++){
        found = model.description(model.index(i));
        QVERIFY(!found.isNull());
        QCOMPARE(found, test[i]);
    }

    //On remove items should slide down.
    for(int i = 1; i<numDescs-1; i++){
        model.remove(model.index(1));
    }
    for(int i = 2; i<numDescs; i++){
        found = model.description(model.index(i));
        QVERIFY(found.isNull());
    }
    found=model.description(model.index(0));
    QVERIFY(!found.isNull());
    QCOMPARE(found,test[0]);
    found=model.description(model.index(1));
    QVERIFY(!found.isNull());
    QCOMPARE(found,test[99%numDescs]);
    model.remove(model.index(1));
    found=model.description(model.index(1));
    QVERIFY(found.isNull());
    model.remove(model.index(0));
    found=model.description(model.index(0));
    QVERIFY(found.isNull());
}