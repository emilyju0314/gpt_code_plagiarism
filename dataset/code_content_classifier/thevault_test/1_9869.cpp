void FlushTiles(vtkRenderer* renderer)
    {
    for (TilesMapType::iterator iter = ::TilesMap.begin();
      iter != :: TilesMap.end(); ++iter)
      {
      vtkTile& tile = iter->second;
      if (tile.TileImage.IsValid())
        {
        double viewport[4];
        renderer->GetViewport(viewport);
        renderer->SetViewport(tile.PhysicalViewport);
        int tile_scale[2];
        renderer->GetVTKWindow()->GetTileScale(tile_scale);
        renderer->GetVTKWindow()->SetTileScale(1, 1);
        tile.TileImage.PushToViewport(renderer);
        renderer->GetVTKWindow()->SetTileScale(tile_scale);
        renderer->SetViewport(viewport);
        }
      }
    }