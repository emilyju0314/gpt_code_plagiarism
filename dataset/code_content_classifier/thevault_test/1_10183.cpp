void QLibHomeScreen::set_event_handler(enum QEventType et, handler_fun f)
{
    HMI_DEBUG("qlibhomescreen", "called.");
    LibHomeScreen::EventType hs_et = (LibHomeScreen::EventType)et;
    return this->mp_hs->set_event_handler(hs_et, std::move(f));
}