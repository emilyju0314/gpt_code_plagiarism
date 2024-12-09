void FileAdapter :: LoadPolicy(const std::shared_ptr<Model>& model) {
    if (this->file_path == "")
        throw CasbinAdapterException("Invalid file path, file path cannot be empty");

    this->LoadPolicyFile(model, LoadPolicyLine);
}