void TimerArrayControl::tick(){

    isTickOngoing = true;

    timerFeed.updateTickTime();

    // handle timeout
    while (timerFeed.root.next && COUNTER_MODULO(timerFeed.cnt - timerFeed.root.next->target) < CALLBACK_JITTER){
        Timer* timer = timerFeed.root.next;

        // set up the next interrupt generation
        if (timer->_periodic){

            // set new target for timer
            uint32_t target = COUNTER_MODULO(timer->target + timer->_delay);

            // find fitting place for timer in string
            timerFeed.updateTimerTarget(timer, target);

        } else {
            // if timer is not periodic, it is done, we can detach it
            Timer* timer = timerFeed.root.next;
            timer->running = false;
            timerFeed.root.next = timer->next;
            timer->next = nullptr;
        }

        // set the new target
        uint32_t target = timerFeed.root.next == nullptr ? COUNTER_MODULO(timerFeed.cnt - 1) : timerFeed.root.next->target;
        __HAL_TIM_SET_COMPARE(timerFeed.htim, TARGET_CC_CHANNEL, target);

        // fire callback
        timer->fire();

        timerFeed.updateTickTime();
    }

    isTickOngoing = false;
}