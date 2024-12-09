bool ImGui::SearchableCombo(const char* label, int* current_item, std::vector<std::string> items, const char* default_preview_text, const char* input_preview_value, int popup_max_height_in_items)
{
    ImGuiContext& g = *GImGui;

    const char* preview_text = NULL;
    if (*current_item >= (int)items.size())
        *current_item = 0;
    if (*current_item >= 0 && *current_item < (int)items.size())
        preview_text = items[*current_item].c_str();
    else
        preview_text = default_preview_text;

    // The old Combo() API exposed "popup_max_height_in_items". The new more general BeginCombo() API doesn't have/need it, but we emulate it here.
    if (popup_max_height_in_items != -1 && !(g.NextWindowData.Flags & ImGuiNextWindowDataFlags_HasSizeConstraint))
        SetNextWindowSizeConstraints(ImVec2(0, 0), ImVec2(FLT_MAX, CalcMaxPopupHeightFromItemCount(popup_max_height_in_items)));

    const int input_size = 64;
    char input_buffer[input_size] = "";
    if (!BeginSearchableCombo(label, preview_text, input_buffer, input_size, input_preview_value, ImGuiComboFlags_None))
        return false;

    // Display items
    // FIXME-OPT: Use clipper (but we need to disable it on the appearing frame to make sure our call to SetItemDefaultFocus() is processed)
    int matched_items = 0;
    bool value_changed = false;
    for (int i = 0; i < (int)items.size(); i++)
    {
        char buffer[input_size] = "";
        ImStrncpy(buffer, input_buffer, input_size);
        std::string input(buffer);
        std::string item = items[i];

        std::transform(item.begin(), item.end(), item.begin(),
            [](unsigned char c) { return (unsigned char)std::tolower(c); });
        std::transform(input.begin(), input.end(), input.begin(),
            [](unsigned char c) { return (unsigned char)std::tolower(c); });

        if (item.find(input, 0) == std::string::npos)
            continue;

        matched_items++;
        PushID((void*)(intptr_t)i);
        const bool item_selected = (i == *current_item);
        const char* item_text = items[i].c_str();
        if (Selectable(item_text, item_selected))
        {
            value_changed = true;
            *current_item = i;
        }
        if (item_selected)
            SetItemDefaultFocus();
        PopID();
    }
    if (matched_items == 0)
        ImGui::Selectable("No maps found", false, ImGuiSelectableFlags_Disabled);

    EndSearchableCombo();

    return value_changed;
}