void ResultsList::update() {
    clear();
    selected_element.reset();

    for(RefRecord * rr : (*results)) {
        std::shared_ptr<ResultLine> line_widget = std::make_shared<ResultLine>(&results->getLastUpdateTimestamp());
        line_widget->setRecord(rr);
        SingleAxisLayoutContainer::addNoLayout(std::move(line_widget), false, true);
    }

    if(begin() != end()) {
        selected_element = front();
    }

    recomputeLayout();
}