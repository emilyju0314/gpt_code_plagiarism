TEST_F(ValidateImage, Issue2463NoSegFault) {
  const std::string spirv = R"(
               OpCapability Linkage
               OpCapability Shader
          %1 = OpExtInstImport "GLSL.std.450"
               OpMemoryModel Logical GLSL450
       %void = OpTypeVoid
          %6 = OpTypeFunction %void
      %float = OpTypeFloat 32
          %8 = OpTypeImage %float 3D 0 0 0 1 Unknown
%_ptr_UniformConstant_8 = OpTypePointer UniformConstant %8
         %10 = OpTypeSampler
%_ptr_UniformConstant_10 = OpTypePointer UniformConstant %10
         %12 = OpTypeSampledImage %8
         %13 = OpTypeFunction %12 %_ptr_UniformConstant_8 %_ptr_UniformConstant_10
         %23 = OpFunction %12 None %13
         %24 = OpFunctionParameter %_ptr_UniformConstant_8
         %25 = OpFunctionParameter %_ptr_UniformConstant_10
         %26 = OpLabel
         %27 = OpLoad %8 %24
         %28 = OpLoad %10 %25
         %29 = OpSampledImage %12 %27 %28
               OpReturnValue %29
               OpFunctionEnd
)";

  CompileSuccessfully(spirv);
  ASSERT_EQ(SPV_ERROR_INVALID_ID, ValidateInstructions());
  EXPECT_THAT(getDiagnosticString(),
              HasSubstr("OpSampledImage instruction must not appear as operand "
                        "for OpReturnValue"));
}