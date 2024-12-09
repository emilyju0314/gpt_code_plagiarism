size_t findPayloadColumn(const std::vector<std::string> &columnNames,
                         const std::string &payloadGroup) {
  const std::string prefix = payloadGroup + '/';
  const std::string suffix = '@' + payloadGroup;
  auto isInPayloadGroup = [&prefix, &suffix](const std::string &name) {
    return eckit::StringTools::beginsWith(name, prefix) ||
           eckit::StringTools::endsWith(name, suffix);
  };
  auto payloadColumnIt = std::find_if(columnNames.begin(), columnNames.end(), isInPayloadGroup);
  if (payloadColumnIt == columnNames.end())
    throw eckit::UserError("No payload column found: no column name begins with '" + prefix +
                           "' or ends with '" + suffix + "'",
                           Here());
  if (std::any_of(payloadColumnIt + 1, columnNames.end(), isInPayloadGroup))
    throw eckit::UserError("Multiple payload candidates found: "
                           "more than one column name begins with '" + prefix +
                           "' or ends with '" + suffix + "'", Here());
  return payloadColumnIt - columnNames.begin();
}