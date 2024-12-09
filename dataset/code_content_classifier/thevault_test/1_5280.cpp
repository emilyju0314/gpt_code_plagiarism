const ts::xml::Element* ts::xml::Document::findModelElement(const Element* elem, const UString& name) const
{
    // Filter invalid parameters.
    if (elem == nullptr || name.empty()) {
        return nullptr;
    }

    // Loop on all children.
    for (const Element* child = elem->firstChildElement(); child != nullptr; child = child->nextSiblingElement()) {
        if (name.similar(child->name())) {
            // Found the child.
            return child;
        }
        else if (child->name().similar(TSXML_REF_NODE)) {
            // The model contains a reference to a child of the root of the document.
            // Example: <_any in="_descriptors"/> => child is the <_any> node.
            // Find the reference name, "_descriptors" in the example.
            const UString refName(child->attribute(TSXML_REF_ATTR).value());
            if (refName.empty()) {
                _report.error(u"invalid XML model, missing or empty attribute 'in' for <%s> at line %d", {child->name(), child->lineNumber()});
            }
            else {
                // Locate the referenced node inside the model root.
                const Document* document = elem->document();
                const Element* root = document == nullptr ? nullptr : document->rootElement();
                const Element* refElem = root == nullptr ? nullptr : root->findFirstChild(refName, true);
                if (refElem == nullptr) {
                    // The referenced element does not exist.
                    _report.error(u"invalid XML model, <%s> not found in model root, referenced in line %d", {refName, child->attribute(TSXML_REF_ATTR).lineNumber()});
                }
                else {
                    // Check if the child is found inside the referenced element.
                    const Element* e = findModelElement(refElem, name);
                    if (e != nullptr) {
                        return e;
                    }
                }
            }
        }
    }

    // Child node not found.
    return nullptr;
}