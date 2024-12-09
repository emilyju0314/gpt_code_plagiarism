const IR::Node *ConvertToDpdkArch::postorder(IR::Type_Control *c) {
    const IR::Type_Control* t = nullptr;
    for (auto kv : structure->pipelines) {
        if (kv.second->type->name != c->name)
            continue;
        t = rewriteControlType(c, kv.first);
    }
    for (auto kv : structure->deparsers) {
        if (kv.second->type->name != c->name)
            continue;
        t = rewriteDeparserType(c, kv.first);
    }
    // Ingress, Egress, IngressDeparser, EgressDeparser are reserved name in psa.p4
    if (c->name == "Ingress" || c->name == "Egress") {
        t = rewriteControlType(c, c->name);
    } else if (c->name == "MainControlT") {
        t = rewriteControlType(c, c->name);
    } else if (c->name == "PreControlT") {
        t = rewriteControlType(c, c->name);
    } else if (c->name == "IngressDeparser" || c->name == "EgressDeparser") {
        t = rewriteDeparserType(c, c->name);
    } else if (c->name == "MainDeparserT") {
        t = rewriteDeparserType(c, c->name);
    }
    return t;
}