TEST(GeoJSONTile, Issue9927) {
    GeoJSONTileTest test;

    CircleLayer layer("circle", "source");

    mapbox::feature::feature_collection<int16_t> features;
    features.push_back(mapbox::feature::feature<int16_t> { mapbox::geometry::point<int16_t>(0, 0) });
    auto data = std::make_shared<FakeGeoJSONData>(std::move(features));
    GeoJSONTile tile(OverscaledTileID(0, 0, 0), "source", test.tileParameters, data);

    Immutable<LayerProperties> layerProperties = makeMutable<CircleLayerProperties>(staticImmutableCast<CircleLayer::Impl>(layer.baseImpl));
    std::vector<Immutable<LayerProperties>> layers { layerProperties };
    tile.setLayers(layers);

    while (!tile.isComplete()) {
        test.loop.runOnce();
    }

    ASSERT_TRUE(tile.isRenderable());
    ASSERT_TRUE(tile.layerPropertiesUpdated(layerProperties));

    // Make sure that once we've had a renderable tile and then receive erroneous data, we retain
    // the previously rendered data and keep the tile renderable.
    tile.setError(std::make_exception_ptr(std::runtime_error("Connection offline")));
    ASSERT_TRUE(tile.isRenderable());
    ASSERT_TRUE(tile.layerPropertiesUpdated(layerProperties));

    // Then simulate a parsing failure and make sure that we keep it renderable in this situation
    // as well. We're using 3 as a correlationID since we've done two three calls that increment
    // this counter (as part of the GeoJSONTile constructor, setLayers, and setPlacementConfig).
    tile.onError(std::make_exception_ptr(std::runtime_error("Parse error")), 3);
    ASSERT_TRUE(tile.isRenderable());
    ASSERT_TRUE(tile.layerPropertiesUpdated(layerProperties));
 }