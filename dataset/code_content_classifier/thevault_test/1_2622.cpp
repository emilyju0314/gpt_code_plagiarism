TEST_F(hdl_parser_vhdl_test, check_add_net_implicit)
{
    TEST_START
    // The net implicit_net will be used in implicit_net but was not declared in the architecture block
    std::stringstream input("-- Device\t: device_name\n"
                            "entity TEST_Comp is\n"
                            "  port (\n"
                            "    net_global_inout : inout STD_LOGIC := 'X';\n"
                            "  );\n"
                            "end TEST_Comp;\n"
                            "architecture STRUCTURE of TEST_Comp is\n"
                            "begin\n"
                            "  gate_0 : INV\n"
                            "    port map (\n"
                            "      O => implicit_net\n"
                            "    );\n"
                            "end STRUCTURE;");
    test_def::capture_stdout();
    hdl_parser_vhdl vhdl_parser(input);
    std::shared_ptr<netlist> nl = vhdl_parser.parse(g_lib_name);
    if (nl == nullptr)
    {
        std::cout << test_def::get_captured_stdout();
    }
    else
    {
        test_def::get_captured_stdout();
    }

    ASSERT_NE(nl, nullptr);

    ASSERT_NE(nl->get_gates("INV").size(), 0);
    std::shared_ptr<gate> g           = *nl->get_gates("INV").begin();
    std::shared_ptr<net> implicit_net = *(nl->get_nets("implicit_net").begin());
    ASSERT_NE(implicit_net, nullptr);
    EXPECT_EQ(implicit_net->get_src().get_gate(), g);
    TEST_END
}