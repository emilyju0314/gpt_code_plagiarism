PassRefPtr<Element> Document::createElement(const QualifiedName& qName, bool createdByParser)
{
    RefPtr<Element> e;

    // FIXME: Use registered namespaces and look up in a hash to find the right factory.
    if (qName.namespaceURI() == xhtmlNamespaceURI)
        e = HTMLElementFactory::createHTMLElement(qName, this, 0, createdByParser);
#if ENABLE(SVG)
    else if (qName.namespaceURI() == SVGNames::svgNamespaceURI)
        e = SVGElementFactory::createSVGElement(qName, this, createdByParser);
#endif
#if ENABLE(WML)
    else if (qName.namespaceURI() == WMLNames::wmlNamespaceURI)
        e = WMLElementFactory::createWMLElement(qName, this, createdByParser);
    else if (isWMLDocument())
        e = WMLElementFactory::createWMLElement(QualifiedName(nullAtom, qName.localName(), WMLNames::wmlNamespaceURI), this, createdByParser);
#endif
#if ENABLE(MATHML)
    else if (qName.namespaceURI() == MathMLNames::mathmlNamespaceURI)
        e = MathMLElementFactory::createMathMLElement(qName, this, createdByParser);
#endif

    if (e)
        m_sawElementsInKnownNamespaces = true;
    else
        e = Element::create(qName, document());

    // <image> uses imgTag so we need a special rule.
#if ENABLE(WML)
    if (!isWMLDocument())
#endif
    ASSERT((qName.matches(imageTag) && e->tagQName().matches(imgTag) && e->tagQName().prefix() == qName.prefix()) || qName == e->tagQName());

    return e.release();
}