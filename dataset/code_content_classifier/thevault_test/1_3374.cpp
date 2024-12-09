TEST(TEST_BASE, test_many_compile_module_to_BRIG)
{
    const char * cpu = "fiji";
    int trials = 5;

    for(int k = 0; k < trials; k++)
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

        // run an optimisation pass over the module
        ret = ROC_ModuleOptimize(dst, 3, 0, 1, cpu);
        ASSERT_TRUE(ret == 1);

        char * output;
        ret = ROC_ModuleEmitBRIG(dst, 2, cpu, &output);
        EXPECT_TRUE(ret > 0);

        char elf_string[] = "\x7f\x45\x4c\x46";

        // check this is an ELF object
        for (size_t i = 0; i < 4; i++)
        {
            EXPECT_TRUE(output[i]==elf_string[i]);
        }

        free(output);

        ROC_ModuleDestroy(dst);
    }
}