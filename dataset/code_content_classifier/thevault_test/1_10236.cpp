void InsuranceGUI::on_cbox_1_1_change(GtkWidget *widget, GtkWidget *data[]) {
    int combobox_counter = 0;
    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 1
    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

        // User chose Opel
        case 0:

            // clear dropdown boxes 2-4 (reset further choices)
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[0]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

            // Fill second dropdown box
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_1", "Opel Corsa");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_2", "Opel Ampera");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_3", "Opel Insignia");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_4", "Opel Zafira");
            break;

            // User chose Audi
        case 1:

            // clear dropdown boxes 2-4 (reset further choices)
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[0]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

            // Fill second dropdown box
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_5", "Audi A1");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_6", "Audi TT");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_7", "Audi Q5");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_8", "Audi A8");
            break;

            // User chose Mercedes
        case 2:

            // clear dropdown boxes 2-4 (reset further choices)
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[0]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

            // Fill second dropdown box
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_9", "Mercedes A");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_10", "Mercedes E");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_11", "Mercedes CLS");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_12", "Mercedes S");
            break;

            // User chose Jaguar
        case 3:

            // clear dropdown boxes 2-4 (reset further choices)
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[0]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

            // Fill second dropdown box
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_13", "Jaguar e-pace");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_14", "Jaguar F-Type");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_15", "Jaguar i-pace");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_16", "Jaguar xj");
            break;
    }

}