void InsuranceGUI::finish_button_clicked(GtkWidget *widget, GtkWidget *data[]) {

    // Close main window doesnt work
    gtk_main_quit();

    gint number = 0;

    // Read Inputs
    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[0]));
    convert_int_to_bit(8, number);

    number = (gtk_combo_box_get_active(GTK_COMBO_BOX(data[1])) + 1) * 100 +
        (gtk_combo_box_get_active(GTK_COMBO_BOX(data[2])) + 1) * 10 +
        (gtk_combo_box_get_active(GTK_COMBO_BOX(data[3])) + 1);
    convert_int_to_bit(16, number);

    for (int i = 4; i < 7; i++) {
        number = atoi(gtk_entry_get_text(GTK_ENTRY(data[i])));
        convert_int_to_bit(8, number);
    }

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[7]));
    convert_int_to_bit(8, number);

    for (int i = 8; i < 9; i++) {
        number = atoi(gtk_entry_get_text(GTK_ENTRY(data[i])));
        convert_int_to_bit(8, number);
    }

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[9]));
    convert_int_to_bit(8, number);

    for (int i = 10; i < 12; i++) {
        number = atoi(gtk_entry_get_text(GTK_ENTRY(data[i])));
        convert_int_to_bit(8, number);
    }

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[12]));
    convert_int_to_bit(8, number);

    number = atoi(gtk_entry_get_text(GTK_ENTRY(data[13])));
    convert_int_to_bit(16, number);

    number = atoi(gtk_entry_get_text(GTK_ENTRY(data[14])));
    convert_int_to_bit(8, number);

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[15]));
    convert_int_to_bit(8, number);

    for (int i = 16; i < 17; i++) {
        number = atoi(gtk_entry_get_text(GTK_ENTRY(data[i])));
        convert_int_to_bit(16, number);
    }

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[17]));
    convert_int_to_bit(8, number);

    for (int i = 18; i < 19; i++) {
        number = atoi(gtk_entry_get_text(GTK_ENTRY(data[i])));
        convert_int_to_bit(8, number);
    }

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[19]));
    convert_int_to_bit(8, number);

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[20]));
    convert_int_to_bit(8, number);

    number = atoi(gtk_entry_get_text(GTK_ENTRY(data[21])));
    convert_int_to_bit(8, number);

    number = atoi(gtk_entry_get_text(GTK_ENTRY(data[22])));
    convert_int_to_bit(16, number);

    for (int i = 23; i < 25; i++) {
        number = atoi(gtk_entry_get_text(GTK_ENTRY(data[i])));
        convert_int_to_bit(8, number);
    }

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[25]));
    convert_int_to_bit(8, number);

    number = atoi(gtk_entry_get_text(GTK_ENTRY(data[26])));
    convert_int_to_bit(16, number);

    for (int i = 27; i < 34; i++) {
        number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[i]));
        convert_int_to_bit(8, number);
    }

}