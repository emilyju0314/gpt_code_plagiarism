TEST_F(ConditionalTests, Flat_Test_8) {
    auto graph = GraphExecutioner::importFromFlatBuffers("./resources/simplewhile_nested.fb");
    auto varSpace = graph->getVariableSpace();
    //graph->printOut();

    auto status = GraphExecutioner::execute(graph);
    ASSERT_EQ(Status::OK(), status);

    ASSERT_TRUE(varSpace->hasVariable(52));

    auto z = varSpace->getVariable(52)->getNDArray();

    ASSERT_NE(nullptr, z);

    //val exp = Nd4j.create(2, 2).assign(15.0);
    auto exp = NDArrayFactory::create<float>('c', {2, 2}, {15, 15, 15, 15});
    ASSERT_TRUE(exp.equalsTo(z));

    delete graph;
}