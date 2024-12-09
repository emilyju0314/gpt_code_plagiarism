std::string GenerateFixedFunctionBlenderGlueCode(const std::string& resultName,
                                                 int entryIndex,
                                                 const SkPaintParamsKey::BlockReader& reader,
                                                 const std::string& priorStageOutputName,
                                                 const std::vector<std::string>& childNames,
                                                 int indent) {
    SkASSERT(childNames.empty());
    SkASSERT(reader.entry()->fUniforms.empty());
    SkASSERT(reader.numDataPayloadFields() == 1);

    // The actual blending is set up via the fixed function pipeline so we don't actually
    // need to access the blend mode in the glue code.

    std::string result;
    add_indent(&result, indent);
    result += "// Fixed-function blending\n";
    add_indent(&result, indent);
    SkSL::String::appendf(&result, "%s = %s;", resultName.c_str(), priorStageOutputName.c_str());

    return result;
}