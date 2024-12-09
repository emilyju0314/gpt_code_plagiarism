std::shared_ptr<Model> Model::NewModelFromFile(const std::string& path) {
    std::shared_ptr<Model> m = NewModel();
    m->LoadModel(path);
    return m;
}