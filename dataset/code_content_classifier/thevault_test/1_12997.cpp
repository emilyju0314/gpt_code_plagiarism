RB_MmProxy* SAIL_ModelFactory::getParentModel(int type) {
    RB_MmProxy* model = NULL;
    std::map<int, RB_MmProxy*>::iterator iter;

    switch (type) {
    case ModelCoordinate:
        iter = mModelList.find(ModelNone);
        break;
    case ModelMap:
        iter = mModelList.find(ModelNone);
        break;
    case ModelProject:
        iter = mModelList.find(ModelNone);
        break;
    case ModelProjectEdit:
        iter = mModelList.find(ModelNone);
        break;
    case ModelRoute:
        iter = mModelList.find(ModelNone);
        break;
    case ModelRouteCoordinate:
        iter = mModelList.find(ModelRoute);
        break;
    case ModelSymbol:
        iter = mModelList.find(ModelNone);
        break;
    case ModelTrack:
        iter = mModelList.find(ModelNone);
        break;
    default:
        iter = mModelList.find(ModelNone);
        RB_DEBUG->print(RB_Debug::D_ERROR,
                        "SAIL_ModelFactory::getParentModel() "
                        "non-existing (parent) model ERROR");
        break;
    }
    if (iter != mModelList.end()) {
        model = (*iter).second;
    }
    return model;
}