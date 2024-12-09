explicit LLVMLoweringPass(
      bool useAlloca = false,
      LLVMPatternListFiller patternListFiller =
          populateStdToLLVMConversionPatterns,
      LLVMTypeConverterMaker converterBuilder = makeStandardToLLVMTypeConverter)
      : patternListFiller(patternListFiller),
        typeConverterMaker(converterBuilder) {}