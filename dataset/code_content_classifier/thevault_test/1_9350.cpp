void Aquarium::loadModel(const G_sceneInfo &info) {
  const ResourceHelper *resourceHelper = mContext->getResourceHelper();
  std::string imagePath = resourceHelper->getImagePath();
  std::string programPath = resourceHelper->getProgramPath();
  std::string modelPath =
      resourceHelper->getModelPath(std::string(info.namestr));

  std::ifstream ModelStream(modelPath, std::ios::in);
  rapidjson::IStreamWrapper is(ModelStream);
  rapidjson::Document document;
  document.ParseStream(is);
  ASSERT(document.IsObject());
  const rapidjson::Value &models = document["models"];
  ASSERT(models.IsArray());

  Model *model;
  if (toggleBitset.test(static_cast<size_t>(TOGGLE::ENABLEALPHABLENDING)) &&
      info.type != MODELGROUP::INNER && info.type != MODELGROUP::OUTSIDE) {
    model = mContext->createModel(this, info.type, info.name, true);
  } else {
    model = mContext->createModel(this, info.type, info.name, info.blend);
  }
  mAquariumModels[info.name] = model;

  auto &value = models.GetArray()[models.GetArray().Size() - 1];
  {
    // set up textures
    const rapidjson::Value &textures = value["textures"];
    for (rapidjson::Value::ConstMemberIterator itr = textures.MemberBegin();
         itr != textures.MemberEnd(); ++itr) {
      std::string name = itr->name.GetString();
      std::string image = itr->value.GetString();

      if (mTextureMap.find(image) == mTextureMap.end()) {
        mTextureMap[image] = mContext->createTexture(name, imagePath + image);
      }

      model->textureMap[name] = mTextureMap[image];
    }

    // set up vertices
    const rapidjson::Value &arrays = value["fields"];
    for (rapidjson::Value::ConstMemberIterator itr = arrays.MemberBegin();
         itr != arrays.MemberEnd(); ++itr) {
      std::string name = itr->name.GetString();
      int numComponents = itr->value["numComponents"].GetInt();
      std::string type = itr->value["type"].GetString();
      Buffer *buffer;
      if (name == "indices") {
        std::vector<unsigned short> vec;
        for (auto &data : itr->value["data"].GetArray()) {
          vec.push_back(data.GetInt());
        }
        buffer = mContext->createBuffer(numComponents, &vec, true);
      } else {
        std::vector<float> vec;
        for (auto &data : itr->value["data"].GetArray()) {
          vec.push_back(data.GetFloat());
        }
        buffer = mContext->createBuffer(numComponents, &vec, false);
      }

      model->bufferMap[name] = buffer;
    }

    // setup program
    // There are 3 programs
    // DM
    // DM+NM
    // DM+NM+RM
    std::string vsId;
    std::string fsId;

    vsId = info.program[0];
    fsId = info.program[1];

    if (vsId != "" && fsId != "") {
      model->textureMap["skybox"] = mTextureMap["skybox"];
    } else if (model->textureMap["reflection"] != nullptr) {
      vsId = "reflectionMapVertexShader";
      fsId = "reflectionMapFragmentShader";

      model->textureMap["skybox"] = mTextureMap["skybox"];
    } else if (model->textureMap["normalMap"] != nullptr) {
      vsId = "normalMapVertexShader";
      fsId = "normalMapFragmentShader";
    } else {
      vsId = "diffuseVertexShader";
      fsId = "diffuseFragmentShader";
    }

    Program *program;
    if (mProgramMap.find(vsId + fsId) != mProgramMap.end()) {
      program = mProgramMap[vsId + fsId];
    } else {
      program = mContext->createProgram(programPath + vsId, programPath + fsId);
      if (toggleBitset.test(static_cast<size_t>(TOGGLE::ENABLEALPHABLENDING)) &&
          info.type != MODELGROUP::INNER && info.type != MODELGROUP::OUTSIDE) {
        program->compileProgram(true, g.alpha);
      } else {
        program->compileProgram(false, g.alpha);
      }
      mProgramMap[vsId + fsId] = program;
    }

    model->setProgram(program);
    model->init();
  }
}