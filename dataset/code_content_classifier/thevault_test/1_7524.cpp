std::string GenerateImageShaderGlueCode(const std::string& resultName,
                                        int entryIndex,
                                        const SkPaintParamsKey::BlockReader& reader,
                                        const std::string& priorStageOutputName,
                                        const std::vector<std::string>& childNames,
                                        int indent) {
    SkASSERT(childNames.empty());

    std::string samplerName = std::string("sampler_") + std::to_string(entryIndex) + "_0";

    std::string subsetName = reader.entry()->getMangledUniformName(0, entryIndex);
    std::string tmXName = reader.entry()->getMangledUniformName(1, entryIndex);
    std::string tmYName = reader.entry()->getMangledUniformName(2, entryIndex);

    std::string result;

    add_indent(&result, indent);
    SkSL::String::appendf(&result,
                          "float2 coords = %s(%s, %s, %s);",
                          reader.entry()->fStaticFunctionName,
                          subsetName.c_str(),
                          tmXName.c_str(),
                          tmYName.c_str());

    add_indent(&result, indent);
    SkSL::String::appendf(&result,
                          "%s = sample(%s, coords);\n",
                          resultName.c_str(),
                          samplerName.c_str());


    return result;
}