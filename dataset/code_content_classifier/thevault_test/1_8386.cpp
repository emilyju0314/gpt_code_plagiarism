void testee1(event_based_actor* self) {
    BOOST_ACTOR_LOGF_TRACE("");
    self->become(after(chrono::milliseconds(10)) >> [=] {
        BOOST_ACTOR_LOGF_TRACE("");
        self->unbecome();
    });
}