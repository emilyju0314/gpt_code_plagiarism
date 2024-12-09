void TimerArrayControl::TimerFeed::updateTimerTarget(Timer* timer, uint32_t target){
    
    // find fitting place for timer in string
    Timer* ins = &root;
    Timer* rem = ins;

    // search attach position
    while(ins->next && isSooner(ins->next->target, target)){
        // while there are more timers and the next timer's target is sooner than the modified one's
        // advance |ins| on the timer string
        ins = ins->next;

        // if the next timer is not our's to remove, advance |rem| on the string
        if (rem->next != timer) rem = ins;
    }

    // search where the timer was, to detach it from that position
    while(rem->next && rem->next != timer) rem = rem->next;

    // only move timer if the predecessor changed and it is not itself
    if (ins != rem && ins != timer){
        // remove our timer from the string
        rem->next = timer->next;

        // insert our timer between |ins| and next of |ins|
        timer->next = ins->next;
        ins->next = timer;
    }

    // update the timer's target
    timer->target = target;
    
    // If the interrupt was set to a timer that has changed, set new target.
    // If ins is first timer, the timer was put to first place.
    // If rem is first timer, the timer was moved from first place.
    // If both, the first timers target was probably changed.
    // In all cases new target is needed.
    if (&root == ins || &root == rem) {
        SET_TARGET(root.next->target);
    }
}