std::shared_ptr<Model> Model::NewModelFromString(const std::string& text) {
    std::shared_ptr<Model> m = NewModel();
    m->LoadModelFromText(text);
    return m;
}