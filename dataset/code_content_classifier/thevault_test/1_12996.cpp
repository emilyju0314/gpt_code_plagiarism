RB_MmProxy* SAIL_ModelFactory::getModel(int type, bool shared) {
    RB_MmProxy* model = NULL;

    if (shared) {
        std::map<int, RB_MmProxy*>::iterator iter;
        iter = mModelList.find(type);
        if (iter != mModelList.end()) {
            // shared model 1- exists or 2- has been removed/deleted and set to NULL
            model = (*iter).second;
        }
        // Model already created
        if (model) return model;
    }

    QSqlDatabase db = getDatabase();

    switch (type) {
    case ModelCoordinate:
        model = getTableModel(db, mObjectFactory, type, "SAIL_CoordinateList", shared);
        model->setSourceSortOrder(RB2::SortOrderAscending, "mname");
        break;
    case ModelMap:
        model = getTableModel(db, mObjectFactory, type, "SAIL_MapList", shared);
        model->setSourceSortOrder(RB2::SortOrderAscending, "mname");
        break;
    case ModelProject:
        model = getTableModel(db, mObjectFactory, type, "SAIL_ProjectList", shared);
        model->setSourceSortOrder(RB2::SortOrderDescending, "created");
        break;
    case ModelProjectEdit:
        model = getTableModel(db, mObjectFactory, type, "SAIL_ProjectList", shared);
        model->setSourceSortOrder(RB2::SortOrderDescending, "created");
        break;
    case ModelRoute:
        model = getTableModel(db, mObjectFactory, type, "SAIL_RouteList", shared);
        break;
    case ModelRouteCoordinate:
        model = getTableModel(db, mObjectFactory, type, "SAIL_RouteCoordinateList", shared);
        model->setSourceSortOrder(RB2::SortOrderAscending, "seqno");
        break;
    case ModelSymbol:
        model = getTableModel(db, mObjectFactory, type, "SAIL_SymbolList", shared);
        model->setSourceSortOrder(RB2::SortOrderAscending, "mname");
        break;
    case ModelTrack:
        model = getTableModel(db, mObjectFactory, type, "SAIL_TrackList", shared);
        break;
    default:
        RB_DEBUG->print(RB_Debug::D_ERROR,
                        "SAIL_ModelFactory::getModel()"
                        "non-existing model ERROR");
        break;
    }

    return model;
}