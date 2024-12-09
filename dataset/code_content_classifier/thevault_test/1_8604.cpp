TEST_F(GraphStateTests, Basic_Tests_1) {
    auto state = (GraphState *) getGraphState(117L);
    ASSERT_EQ(117L, state->id());

    // this call will create scope internally
    state->registerScope(119);

    sd::ops::add opA;
    sd::ops::LegacyTransformSameOp opB(transform::Neg); // simdOps::Neg

    ArgumentsList argsA;
    ArgumentsList argsB;

    state->attachOpToScope(119, 1, &opA, argsA);
    state->attachOpToScope(119, 2, &opB, argsB);

    auto scope = state->getScope(119);
    ASSERT_TRUE(scope != nullptr);
    ASSERT_EQ(2, scope->size());

    deleteGraphState(state);
}