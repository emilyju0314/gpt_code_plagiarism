std::string GenerateShaderBasedBlenderGlueCode(const std::string& resultName,
                                               int entryIndex,
                                               const SkPaintParamsKey::BlockReader& reader,
                                               const std::string& priorStageOutputName,
                                               const std::vector<std::string>& childNames,
                                               int indent) {
    SkASSERT(childNames.empty());
    SkASSERT(reader.entry()->fUniforms.empty());
    SkASSERT(reader.numDataPayloadFields() == 1);

    SkSpan<const uint8_t> blendMode = reader.bytes(0);
    SkASSERT(blendMode.size() == 1);
    SkASSERT(blendMode[0] <= static_cast<int>(SkBlendMode::kLastMode));

    std::string result;

    add_indent(&result, indent);
    result += "// Shader-based blending\n";
    // TODO: emit code to perform dest read
    add_indent(&result, indent);
    result += "half4 dummyDst = half4(1.0, 1.0, 1.0, 1.0);\n";

    add_indent(&result, indent);
    SkSL::String::appendf(&result, "%s = %s(%d, %s, dummyDst);",
                          resultName.c_str(),
                          reader.entry()->fStaticFunctionName,
                          blendMode[0],
                          priorStageOutputName.c_str());

    return result;
}