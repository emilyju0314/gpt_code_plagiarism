static void testTimerChannels(timer_dev *dev) {
    switch (dev->type) {
    case TIMER_BASIC:
        v_putstr("Skipping basic timer ");
        v_puttimn(dev);
        v_println();
        return;
    case TIMER_ADVANCED:
    case TIMER_GENERAL:
        // Set up
        v_puttimn(dev);
        v_println();
        v_putstr("\tchannels: ");

        timer_num = timerNumber(dev);
        timer_pause(dev);
        count1 = 0;
        count2 = 0;
        count3 = 0;
        count4 = 0;
        timer_set_reload(dev, 0xFFFF);
        timer_set_prescaler(dev, 1);
        for (int c = 1; c <= 4; c++) {
            if (timer_has_cc_ch(dev, c)) {
                v_putudec(c);
                v_putstr("\t");
                timer_set_compare(dev, c, 0xFFFF);
                timer_set_mode(dev, c, TIMER_OUTPUT_COMPARE);
                timer_attach_interrupt(dev, c, handlers[c - 1]);
            }
        }
        v_println();

        // Run test
        timer_generate_update(dev);
        timer_resume(dev);
        _delay(250);
        timer_pause(dev);

        // Print results
        v_putstr("\tcounts:   ");
        bool fail = false;
        bool mismatched[4] = {false, false, false, false};
        int counts[4];
        counts[0] = count1;
        counts[1] = count2;
        counts[2] = count3;
        counts[3] = count4;
        bool first = true;
        int first_count = -1;
        for (int c = 1; c <= 4; c++) {
            if (timer_has_cc_ch(dev, c)) {
                if (first) {
                    first_count = counts[c - 1];
                    first = false;
                }
                if (!first && (counts[c - 1] != first_count)) {
                    mismatched[c - 1] = true;
                    fail = true;
                }
                v_putudec(counts[c - 1]);
                v_putstr("\t");
            }
        }
        v_println();
        if (fail) {
            for (int i = 0; i < 4; i++) {
                if (mismatched[i]) {
                    putstr("*** FAIL: mismatch on ");
                    puttimn(dev);
                    putstr(", channel ");
                    putudec(i + 1);
                    putstr(": expected ");
                    putudec(first_count);
                    putstr(", got ");
                    putudec(counts[i]);
                    println();
                }
            }
        } else {
            puttimn(dev);
            putstrln(" [ok]");
        }
        v_println();

        // Clean up
        for (int c = 1; c <= 4; c++) {
            if (timer_has_cc_ch(dev, c)) {
                timer_set_mode(dev, c, TIMER_DISABLED);
            }
        }
        break;
    }
}