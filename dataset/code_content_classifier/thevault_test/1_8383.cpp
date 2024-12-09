void spawn5_server(event_based_actor* self, actor client, bool inverted) {
    if (!inverted) spawn5_server_impl(self, client, group::get("local", "foobar"));
    else {
        BOOST_ACTOR_PRINT("request group");
        self->sync_send(client, atom("GetGroup")).then (
            [=](const group& remote_group) {
                spawn5_server_impl(self, client, remote_group);
            }
        );
    }
}