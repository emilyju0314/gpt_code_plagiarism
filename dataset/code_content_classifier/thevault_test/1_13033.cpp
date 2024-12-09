Event* Stream::GetStreamEvent()
    {
        Event* event = new Event;
        event->Record(this);
        return event;  
    }