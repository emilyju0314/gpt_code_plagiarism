void graph_graphics_widget::handle_add_gates_to_new_module_triggered()
{
    auto dialog = new input_dialog(nullptr, "Name:");
    if (dialog->exec() == QDialog::Accepted)
    {
        auto sub = g_netlist->create_module(g_netlist->get_unique_module_id(), dialog->get_text().toStdString(), g_netlist->get_top_module());
        for (const auto& gate : currently_selected_gates)
            sub->assign_gate(gate->get_ref_gate());
    }
    delete dialog;
}