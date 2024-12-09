void tst_QFavoriteServicesModel::init()
{
    QFavoriteServicesModel model;
    int max = model.rowCount();
    for(int i = 0; i<max; i++)
        model.remove(model.index(0));
}