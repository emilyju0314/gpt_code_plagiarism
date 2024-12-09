static std::string GetArgumentList(
        std::map<std::string, headcode::crypt::Algorithm::Description::ArgumentDefinition> const & arguments,
        std::string const & indent = "    ") {

    if (arguments.empty()) {
        return std::string{"n/a"};
    }

    std::stringstream ss;
    for (auto const & [name, definition] : arguments) {
        ss << indent << "Name: " << name << std::endl;
        ss << indent << indent << "Description: " << definition.description_ << std::endl;
        ss << indent << indent << "Size: " << GetBlockSizeText(definition.size_) << std::endl;
        ss << indent << indent
           << "Padding strategy: " << headcode::crypt::GetPaddingStrategyText(definition.padding_strategy_)
           << std::endl;
        ss << indent << indent << "Mandatory: " << (definition.optional_ ? "no" : "yes") << std::endl;
    }

    return ss.str();
}