TEST_F(hdl_parser_vhdl_test, check_generic_map){TEST_START{// A boolean value is passed
                                                           std::stringstream input("-- Device\t: device_name\n"
                                                                                   "entity TEST_Comp is\n"
                                                                                   "  port (\n"
                                                                                   "    net_global_inout : inout STD_LOGIC := 'X';\n"
                                                                                   "  );\n"
                                                                                   "end TEST_Comp;\n"
                                                                                   "architecture STRUCTURE of TEST_Comp is\n"
                                                                                   "begin\n"
                                                                                   "  gate_0 : INV\n"
                                                                                   "    generic map(\n"
                                                                                   "      key_bool => true\n"
                                                                                   "    )\n"
                                                                                   "    port map (\n"
                                                                                   "      I => net_global_inout\n"
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
std::shared_ptr<gate> g = *nl->get_gates("INV").begin();
EXPECT_EQ(g->get_data_by_key("generic", "key_bool"), std::make_tuple("boolean", "true"));
}