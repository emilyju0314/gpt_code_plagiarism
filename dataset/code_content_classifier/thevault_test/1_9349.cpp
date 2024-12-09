void Aquarium::loadPlacement() {
  const ResourceHelper *resourceHelper = mContext->getResourceHelper();
  std::string proppath = resourceHelper->getPropPlacementPath();
  std::ifstream PlacementStream(proppath, std::ios::in);
  rapidjson::IStreamWrapper isPlacement(PlacementStream);
  rapidjson::Document document;
  document.ParseStream(isPlacement);

  ASSERT(document.IsObject());

  ASSERT(document.HasMember("objects"));
  const rapidjson::Value &objects = document["objects"];
  ASSERT(objects.IsArray());

  for (rapidjson::SizeType i = 0; i < objects.Size(); ++i) {
    const rapidjson::Value &name = objects[i]["name"];
    const rapidjson::Value &worldMatrix = objects[i]["worldMatrix"];
    ASSERT(worldMatrix.IsArray() && worldMatrix.Size() == 16);

    std::vector<float> matrix;
    for (rapidjson::SizeType j = 0; j < worldMatrix.Size(); ++j) {
      matrix.push_back(worldMatrix[j].GetFloat());
    }

    MODELNAME modelname = mModelEnumMap[name.GetString()];
    mAquariumModels[modelname]->worldmatrices.push_back(matrix);
  }
}