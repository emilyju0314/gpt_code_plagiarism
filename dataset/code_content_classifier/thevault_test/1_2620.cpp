TEST_F(hdl_parser_vhdl_test, check_main_example)
{
    TEST_START
    std::stringstream input("-- Device\t: device_name\n"
                            "library IEEE;\n"
                            "use IEEE.STD_LOGIC_1164.ALL;\n"
                            "library SIMPRIM;\n"
                            "use SIMPRIM.VCOMPONENTS.ALL;\n"
                            "use SIMPRIM.VPKG.ALL;\n"
                            "\n"
                            "entity TEST_Comp is\n"
                            "  port (\n"
                            "    net_global_in : in STD_LOGIC := 'X';\n"
                            "    net_global_out : out STD_LOGIC := 'X';\n"
                            "    net_global_inout : inout STD_LOGIC := 'X';\n"
                            "  );\n"
                            "end AES_Comp;\n"
                            "\n"
                            "architecture STRUCTURE of TEST_Comp is\n"
                            "  signal net_0 : STD_LOGIC;\n"
                            "  signal vec_net : STD_LOGIC_VECTOR ( 2 downto 0 );\n"
                            "  attribute PTYPE: IGNORE_ME;\n"
                            "begin\n"
                            "  gate_0 : INV\n"
                            "    port map (\n"
                            "      I => net_global_in,\n"
                            "      O => net_0\n"
                            "    );\n"
                            "  gate_1 : AND2\n"
                            "    port map (\n"
                            "      I0 => net_global_in,\n"
                            "      I1 => net_global_in,\n"
                            "      O => vec_net(2)\n"
                            "    );\n"
                            "  gate_2 : AND3\n"
                            "    port map (\n"
                            "      I0 => net_0,\n"
                            "      I1 => vec_net(2),\n"
                            "      O => net_global_out\n"
                            "    );\n"
                            "end STRUCTURE;\n"
                            "");
    //test_def::capture_stdout();
    hdl_parser_vhdl vhdl_parser(input);
    std::shared_ptr<netlist> nl = vhdl_parser.parse(g_lib_name);
    if (nl == nullptr)
    {
        //std::cout << test_def::get_captured_stdout();
    }
    else
    {
        //test_def::get_captured_stdout();
    }

    ASSERT_NE(nl, nullptr);

    // Check if the device name is parsed correctly
    EXPECT_EQ(nl->get_device_name(), "device_name");

    // Check if the gates are parsed correctly
    ASSERT_EQ(nl->get_gates("INV").size(), 1);
    std::shared_ptr<gate> gate_0 = *(nl->get_gates("INV").begin());
    ASSERT_EQ(nl->get_gates("AND2").size(), 1);
    std::shared_ptr<gate> gate_1 = *(nl->get_gates("AND2").begin());
    ASSERT_EQ(nl->get_gates("AND3").size(), 1);
    std::shared_ptr<gate> gate_2 = *(nl->get_gates("AND3").begin());

    ASSERT_NE(gate_0, nullptr);
    EXPECT_EQ(gate_0->get_name(), "gate_0");

    ASSERT_NE(gate_1, nullptr);
    EXPECT_EQ(gate_1->get_name(), "gate_1");

    ASSERT_NE(gate_2, nullptr);
    EXPECT_EQ(gate_2->get_name(), "gate_2");

    // Check if the nets are parsed correctly
    std::shared_ptr<net> net_0            = *(nl->get_nets("net_0").begin());
    std::shared_ptr<net> vec_net_2        = *(nl->get_nets("vec_net(2)").begin());
    std::shared_ptr<net> net_global_in    = *(nl->get_nets("net_global_in").begin());
    std::shared_ptr<net> net_global_out   = *(nl->get_nets("net_global_out").begin());
    std::shared_ptr<net> net_global_inout = *(nl->get_nets("net_global_inout").begin());

    ASSERT_NE(net_0, nullptr);
    EXPECT_EQ(net_0->get_name(), "net_0");
    EXPECT_EQ(net_0->get_src(), get_endpoint(gate_0, "O"));
    std::vector<endpoint> exp_net_0_dsts = {get_endpoint(gate_2, "I0")};
    EXPECT_TRUE(vectors_have_same_content(net_0->get_dsts(), std::vector<endpoint>({get_endpoint(gate_2, "I0")})));

    ASSERT_NE(vec_net_2, nullptr);
    EXPECT_EQ(vec_net_2->get_name(), "vec_net(2)");
    EXPECT_EQ(vec_net_2->get_src(), get_endpoint(gate_1, "O"));
    EXPECT_TRUE(vectors_have_same_content(vec_net_2->get_dsts(), std::vector<endpoint>({get_endpoint(gate_2, "I1")})));

    ASSERT_NE(net_global_in, nullptr);
    EXPECT_EQ(net_global_in->get_name(), "net_global_in");
    EXPECT_EQ(net_global_in->get_src(), get_endpoint(nullptr, ""));
    EXPECT_TRUE(vectors_have_same_content(net_global_in->get_dsts(), std::vector<endpoint>({get_endpoint(gate_0, "I"), get_endpoint(gate_1, "I0"), get_endpoint(gate_1, "I1")})));
    EXPECT_TRUE(nl->is_global_input_net(net_global_in));

    ASSERT_NE(net_global_out, nullptr);
    EXPECT_EQ(net_global_out->get_name(), "net_global_out");
    EXPECT_EQ(net_global_out->get_src(), get_endpoint(gate_2, "O"));
    EXPECT_TRUE(net_global_out->get_dsts().empty());
    EXPECT_TRUE(nl->is_global_output_net(net_global_out));

    ASSERT_NE(net_global_inout, nullptr);
    EXPECT_EQ(net_global_inout->get_name(), "net_global_inout");
    EXPECT_EQ(net_global_inout->get_src(), get_endpoint(nullptr, ""));
    EXPECT_TRUE(net_global_inout->get_dsts().empty());
    EXPECT_TRUE(nl->is_global_inout_net(net_global_inout));

    EXPECT_EQ(nl->get_global_input_nets().size(), 1);
    EXPECT_EQ(nl->get_global_output_nets().size(), 1);
    EXPECT_EQ(nl->get_global_inout_nets().size(), 1);

    // TODO: Some more stored information, cout capture
    TEST_END
}