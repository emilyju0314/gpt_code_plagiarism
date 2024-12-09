TEST(UpdateRenderables, LoadOverscaledMaxZoomTile) {
    ActionLog log;
    MockSource source;
    auto getTileData = getTileDataFn(log, source.dataTiles);
    auto createTileData = createTileDataFn(log, source.dataTiles);
    auto retainTileData = retainTileDataFn(log);
    auto renderTile = renderTileFn(log);

    source.zoomRange.max = 2;
    source.idealTiles.emplace(OverscaledTileID{4, 0, {2, 0, 0}});

    auto tile_4_2_0_0 = source.createTileData(OverscaledTileID{ 4, 0, { 2, 0, 0 } });
    tile_4_2_0_0->renderable = false;
    tile_4_2_0_0->triedOptional = true;
    tile_4_2_0_0->loaded = true;

    auto tile_3_2_0_0 = source.createTileData(OverscaledTileID{ 3, 0, { 2, 0, 0 } });
    tile_3_2_0_0->renderable = false;
    tile_3_2_0_0->triedOptional = true;
    tile_3_2_0_0->loaded = true;

    auto tile_2_2_0_0 = source.createTileData(OverscaledTileID{ 2, 0, { 2, 0, 0 } });
    tile_2_2_0_0->renderable = false;
    tile_2_2_0_0->triedOptional = true;
    tile_2_2_0_0->loaded = true;

    // Tile level 1 won't be overscaled.
    auto tile_1_1_0_0 = source.createTileData(OverscaledTileID{ 1, 0, { 1, 0, 0 } });
    tile_1_1_0_0->renderable = true;
    tile_1_1_0_0->triedOptional = true;
    tile_1_1_0_0->loaded = true;

    algorithm::updateRenderables(
        getTileData, createTileData, retainTileData, renderTile, source.idealTiles, source.zoomRange);
    EXPECT_EQ(ActionLog({
                  GetTileDataAction{ { 4, 0, { 2, 0, 0 } }, Found },
                  RetainTileDataAction{ { 4, 0, { 2, 0, 0 } }, TileNecessity::Required },
                  GetTileDataAction{ { 5, 0, { 2, 0, 0 } }, NotFound },
                  GetTileDataAction{ { 3, 0, { 2, 0, 0 } }, Found },
                  RetainTileDataAction{ { 3, 0, { 2, 0, 0 } }, TileNecessity::Required },
                  GetTileDataAction{ { 2, 0, { 2, 0, 0 } }, Found },
                  RetainTileDataAction{ { 2, 0, { 2, 0, 0 } }, TileNecessity::Required },
                  GetTileDataAction{ { 1, 0, { 1, 0, 0 } }, Found },
                  RetainTileDataAction{ { 1, 0, { 1, 0, 0 } }, TileNecessity::Required },
                  RenderTileAction{ { 1, 0, 0 }, *tile_1_1_0_0 },
              }),
              log);
}