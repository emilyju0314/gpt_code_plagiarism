TEST_F(ValidateImage, ZeroExtendScalarUIntTexelV14Good) {
  // Unsigned int sampled type
  const std::string body = R"(
%img = OpLoad %type_image_u32_2d_0002 %uniform_image_u32_2d_0002
%res1 = OpImageRead %u32 %img %u32vec2_01 ZeroExtend
)";
  const std::string extra = "\nOpCapability StorageImageReadWithoutFormat\n";

  CompileSuccessfully(
      GenerateShaderCode(body, extra, "Fragment", "", SPV_ENV_UNIVERSAL_1_4),
      SPV_ENV_UNIVERSAL_1_4);
  EXPECT_EQ(SPV_SUCCESS, ValidateInstructions(SPV_ENV_UNIVERSAL_1_4));
  EXPECT_THAT(getDiagnosticString(), Eq(""));
}