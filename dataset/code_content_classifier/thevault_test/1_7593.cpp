void FilteredFileAdapter :: LoadFilteredPolicy(const std::shared_ptr<Model>& model, Filter* filter) {
    if (filter == NULL) {
        this->LoadPolicy(model);
    }

    if (this->file_path == "") {
        throw CasbinAdapterException("Invalid file path, file path cannot be empty");
    }

    this->loadFilteredPolicyFile(model, filter, LoadPolicyLine);
    this->filtered = true;
}