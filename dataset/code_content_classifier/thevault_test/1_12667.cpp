void Grammar::walkExpansion(Expansion * e, void (* callback)(Expansion *)) {
    callback(e);
    if(e->hasChild()) {
        for(unsigned int i = 0; i < e->childCount(); i++) {
            Grammar::walkExpansion(e->getChild(i).get(), callback);
        }
    }
}