TEST(TEST_BASE, test_parse_ir_module)
{
    std::string ir = read_ir_from_file("demo_ir.ll");
    ModuleRef* theRef = ROC_ParseModule(ir.c_str());
    ROC_ModuleDestroy(theRef);
}