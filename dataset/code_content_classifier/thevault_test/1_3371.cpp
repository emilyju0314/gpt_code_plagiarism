TEST(TEST_BASE, test_parse_bc_module)
{
    std::string bc = read_bc_from_file("opencl.amdgcn.bc");
    ModuleRef* theRef = ROC_ParseBitcode(bc.c_str(), bc.size());
    ROC_ModuleDestroy(theRef);
}