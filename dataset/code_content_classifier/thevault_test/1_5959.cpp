TEST_F(LhloGenTest, AddAsKernel) {
  CompileAndVerifyIr(
      tensorflow::io::JoinPath("tensorflow", "compiler", "xla", "service",
                               "mlir_gpu", "tests", "add_as_kernel.hlo"),
      LoweringStage::KERNEL);
}