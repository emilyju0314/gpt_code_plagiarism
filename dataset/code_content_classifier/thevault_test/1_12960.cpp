void ConeLight::addNearEdge()
    {
        float p = nearDistance_ * tanf(coneAngle_);

        b2Vec2 pt = b2Mul(finalTransform(), b2Vec2(nearDistance_, -p));
        b2Vec2 endPt = b2Mul(finalTransform(), b2Vec2(nearDistance_, p));

        b2Vec2 v = (endPt - pt).Skew();
        v.Normalize();

        size_t bv = edgeVertices_.size();
        size_t bc = edgeColors_.size();
        size_t bs = edgeS_.size();

        appendTriangleStrip(edgeVertices_, pt.x, pt.y, bv);
        appendColorStrip(edgeColors_, color(), bc);
        appendGenericStrip(edgeS_, nearS(1.0f), bs);

        b2Vec2 tmp = pt + settings.light.edgeSmooth * v;

        appendTriangleStrip(edgeVertices_, tmp.x, tmp.y, bv);
        appendColorStrip(edgeColors_, Color(0.0f, 0.0f, 0.0f, 0.0f), bc);
        appendGenericStrip(edgeS_, nearS(1.0f), bs);

        appendTriangleStrip(edgeVertices_, endPt.x, endPt.y, bv);
        appendColorStrip(edgeColors_, color(), bc);
        appendGenericStrip(edgeS_, nearS(1.0f), bs);

        tmp = endPt + settings.light.edgeSmooth * v;

        appendTriangleStrip(edgeVertices_, tmp.x, tmp.y, bv);
        appendColorStrip(edgeColors_, Color(0.0f, 0.0f, 0.0f, 0.0f), bc);
        appendGenericStrip(edgeS_, nearS(1.0f), bs);
    }