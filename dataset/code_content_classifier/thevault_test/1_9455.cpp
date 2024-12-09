void EmitFunctionContext::i16x8_q15mulr_sat_s(NoImm)
{
	llvm::Value* right = pop();
	llvm::Value* left = pop();
	left = irBuilder.CreateBitCast(left, llvmContext.i16x8Type);
	right = irBuilder.CreateBitCast(right, llvmContext.i16x8Type);

	// Extend the inputs to 64-bit to avoid overflow.
	left = irBuilder.CreateSExt(left, llvmContext.i64x8Type);
	right = irBuilder.CreateSExt(right, llvmContext.i64x8Type);

	// result = saturateS16((left * right + 0x4000) >> 15)
	llvm::Value* product = irBuilder.CreateMul(left, right);
	llvm::Value* sum = irBuilder.CreateAdd(
		product, irBuilder.CreateVectorSplat(8, emitLiteral(llvmContext, U64(0x4000))));
	llvm::Value* shift = irBuilder.CreateAShr(sum, 15);
	llvm::Value* minSplat
		= irBuilder.CreateVectorSplat(8, emitLiteral(llvmContext, I64(INT16_MIN)));
	llvm::Value* maxSplat
		= irBuilder.CreateVectorSplat(8, emitLiteral(llvmContext, I64(INT16_MAX)));
	llvm::Value* saturate = irBuilder.CreateSelect(
		irBuilder.CreateICmpSGT(shift, maxSplat),
		maxSplat,
		irBuilder.CreateSelect(irBuilder.CreateICmpSLT(shift, minSplat), minSplat, shift));
	llvm::Value* result = irBuilder.CreateTrunc(saturate, llvmContext.i16x8Type);
	push(result);
}