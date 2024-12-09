TEST_F(ConditionalTests, Flat_Test_3) {
    sd::ops::identity op0;

    auto graph = GraphExecutioner::importFromFlatBuffers("./resources/simplewhile_0_3.fb");
    auto varSpace = graph->getVariableSpace();
    varSpace->getVariable(1)->getNDArray()->assign(1.0);

    //graph->printOut();

    auto status = GraphExecutioner::execute(graph);
    ASSERT_EQ(Status::OK(), status);

    ASSERT_TRUE(varSpace->hasVariable(17));

    auto z = varSpace->getVariable(17)->getNDArray();

    ASSERT_NE(nullptr, z);

    auto exp = NDArrayFactory::create<float>('c', {2, 2}, {1, 1, 1, 1});
    ASSERT_TRUE(exp.equalsTo(z));

    delete graph;
}