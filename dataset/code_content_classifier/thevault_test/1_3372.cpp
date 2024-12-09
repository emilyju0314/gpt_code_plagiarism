TEST(TEST_BASE, test_compile_module_to_HSAIL)
{
    ROC_Initialize();
    std::string ir = read_ir_from_file("demo_ir.ll");
    ModuleRef* dst = ROC_ParseModule(ir.c_str());

    int ret;

    for (auto& bitcode : _bitcodes)
    {

        std::string builtins_bc = read_bc_from_file(bitcode.c_str());
        ModuleRef* bc_src = ROC_ParseBitcode(builtins_bc.c_str(),
                                             builtins_bc.size());

        // link the builtins into the module
        ret = ROC_ModuleLinkIn(dst, bc_src);
        EXPECT_TRUE(ret != 0);

        ROC_ModuleDestroy(bc_src);
    }

    const char * cpu = "fiji";

    // run an optimisation pass over the module
    ret = ROC_ModuleOptimize(dst, 3, 0, 1, cpu);
    ASSERT_TRUE(ret == 1);

    char * output;
    ret = ROC_ModuleEmitHSAIL(dst, 2, cpu, &output);
    EXPECT_TRUE(ret > 0);
    std::string hsail(output);

    // check this is an HSA code object, search the dump for an HSA ISA string
    // like '.hsa_code_object_isa 8,0,3,"AMD","AMDGPU"'
    std::regex regex(".*\\.hsa_code_object_isa.*\"AMD\",\"AMDGPU\".*");
    EXPECT_TRUE(std::regex_search(hsail, regex));
    free(output);

    ROC_ModuleDestroy(dst);
}