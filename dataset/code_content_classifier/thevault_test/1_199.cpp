static void testPauseAndResume(timer_dev *dev) {
    timer_dev *base_dev = getDifferentTimerOnSameBusAs(dev);
    unsigned start_count = 0, reload = 65535;
    // This prescaler should be enough to ensure that we don't
    // overflow, while still giving us a reasonably large number of
    // timer ticks.
    uint16 prescaler = CYCLES_PER_MICROSECOND * 50;
    double epsilon = .02;

    if (rcc_dev_clk(base_dev->clk_id) != rcc_dev_clk(dev->clk_id)) {
        putstrln("*** ERROR: cannot run test. Bus info is messed up.");
        return;
    }

    // Pause and set up timers
    timer_pause(base_dev);
    timer_pause(dev);
    timer_set_count(base_dev, start_count);
    timer_set_count(dev, start_count);
    timer_set_reload(base_dev, reload);
    timer_set_reload(dev, reload);
    timer_set_prescaler(base_dev, prescaler);
    timer_set_prescaler(dev, prescaler);
    timer_generate_update(base_dev);
    timer_generate_update(dev);

    // Resume the timers and run the test
    ASSERT(timer_get_count(base_dev) == start_count);
    ASSERT(timer_get_count(dev) == start_count);
    timer_resume(base_dev);
    timer_resume(dev);
    _delay(1000);
    timer_pause(dev);
    _delay(1000);
    timer_pause(base_dev);

    // Check the results
    unsigned dev_count = timer_get_count(dev);
    unsigned base_count = timer_get_count(base_dev);
    double count_ratio = ((double)dev_count / base_count);
    bool fail = false;
    if (count_ratio > 0.5 + epsilon || count_ratio < 0.5 - epsilon) {
        fail = true;
    }
    if (fail || verbose) {
        puttimn(dev);
        putstr(" vs. ");
        puttimn(base_dev);
        putstr(": ");
        if (fail) putstr("*** FAIL: ");
        else putstr("[ok] ");
        putstr("(dev = ");
        putudec(dev_count);
        putstr(") / (base = ");
        putudec(base_count);
        putstr(") = ");
        // hack hack hack
        putudec((int)count_ratio);
        count_ratio -= (int)count_ratio;
        putstr(".");
        int cr_x_100 = (int)(count_ratio * 100);
        int hundredths = cr_x_100 % 10;
        cr_x_100 /= 10;
        int tenths = cr_x_100 % 10;
        putudec(tenths);
        putudec(hundredths);
        println();
    }
}