void FilteredFileAdapter :: SavePolicy(const std::shared_ptr<Model>& model) {
    if (this->filtered) {
        throw CasbinAdapterException("Cannot save a filtered policy");
    }
    this->SavePolicy(model);
}