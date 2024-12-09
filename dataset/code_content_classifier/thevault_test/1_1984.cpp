void executive::CooperativeThreadArray::eval_Reconverge(
	CTAContext &context, const ir::PTXInstruction &instr) {
	using namespace std;
	trace();
	
	// dispatch
	reconvergenceMechanism->eval_Reconverge(context, instr);
}