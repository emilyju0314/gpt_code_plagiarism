void EmitFunctionContext::memory_grow(MemoryImm imm)
{
	llvm::Value* deltaNumPages = pop();
	ValueVector resultTuple = emitRuntimeIntrinsic(
		"memory.grow",
		FunctionType(TypeTuple(moduleContext.iptrValueType),
					 TypeTuple({moduleContext.iptrValueType, moduleContext.iptrValueType}),
					 IR::CallingConvention::intrinsic),
		{zext(deltaNumPages, moduleContext.iptrType),
		 getMemoryIdFromOffset(moduleContext.memoryOffsets[imm.memoryIndex])});
	WAVM_ASSERT(resultTuple.size() == 1);
	const MemoryType& memoryType = moduleContext.irModule.memories.getType(imm.memoryIndex);
	push(coerceIptrToIndex(memoryType.indexType, resultTuple[0]));
}