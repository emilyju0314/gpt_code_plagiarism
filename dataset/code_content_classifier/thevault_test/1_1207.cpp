std::tuple<const IR::P4Table*, cstring>
SplitP4TableCommon::create_match_table(const IR::P4Table *tbl) {
    cstring actionName;
    if (implementation == TableImplementation::ACTION_SELECTOR) {
        actionName = refMap->newName(tbl->name + "_set_group_id");
    } else if (implementation == TableImplementation::ACTION_PROFILE) {
        actionName = refMap->newName(tbl->name + "_set_member_id");
    } else {
        BUG("Unexpected table implementation type");
    }
    auto hidden = new IR::Annotations();
    hidden->add(new IR::Annotation(IR::Annotation::hiddenAnnotation, {}));
    IR::Vector<IR::KeyElement> match_keys;
    for (auto key : tbl->getKey()->keyElements) {
        if (key->matchType->toString() != "selector") {
            match_keys.push_back(key);
        }
    }
    IR::IndexedVector<IR::ActionListElement> actionsList;

    auto actionCall = new IR::MethodCallExpression(new IR::PathExpression(actionName));
    actionsList.push_back(new IR::ActionListElement(actionCall));
    actionsList.push_back(new IR::ActionListElement(tbl->getDefaultAction()));
    IR::IndexedVector<IR::Property> properties;
    properties.push_back(new IR::Property("actions", new IR::ActionList(actionsList), false));
    properties.push_back(new IR::Property("key", new IR::Key(match_keys), false));
    properties.push_back(new IR::Property("default_action",
                         new IR::ExpressionValue(tbl->getDefaultAction()), false));
    if (tbl->getSizeProperty()) {
        properties.push_back(new IR::Property("size",
                             new IR::ExpressionValue(tbl->getSizeProperty()), false)); }
    auto match_table = new IR::P4Table(tbl->name, new IR::TableProperties(properties));
    return std::make_tuple(match_table, actionName);
}