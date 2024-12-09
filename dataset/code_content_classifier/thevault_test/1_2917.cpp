bool LoadBasicGrids() {

  INFO_LOGF("Loading DEM: %s", g_basicConfig->GetDEM());
  char *ext = strrchr(g_basicConfig->GetDEM(), '.');
  if (!strcasecmp(ext, ".asc")) {
    g_DEM = ReadFloatAscGrid(g_basicConfig->GetDEM());
  } else {
    g_DEM = ReadFloatTifGrid(g_basicConfig->GetDEM());
  }
  if (!g_DEM) {
    ERROR_LOG("Failed to load DEM!");
    return false;
  }

  INFO_LOGF("Loading DDM: %s", g_basicConfig->GetDDM());
  ext = strrchr(g_basicConfig->GetDDM(), '.');
  if (!strcasecmp(ext, ".asc")) {
    g_DDM = ReadFloatAscGrid(g_basicConfig->GetDDM());
  } else {
    g_DDM = ReadFloatTifGrid(g_basicConfig->GetDDM());
  }
  if (!g_DDM) {
    ERROR_LOG("Failed to load DDM!");
    return false;
  }
  if (!g_DEM->IsSpatialMatch(g_DDM)) {
    ERROR_LOG("The spatial characteristics of the DEM and DDM differ!");
    return false;
  }

  INFO_LOGF("Loading FAM: %s", g_basicConfig->GetFAM());
  ext = strrchr(g_basicConfig->GetFAM(), '.');
  if (!strcasecmp(ext, ".asc")) {
    g_FAM = ReadFloatAscGrid(g_basicConfig->GetFAM());
  } else {
    g_FAM = ReadFloatTifGrid(g_basicConfig->GetFAM());
  }
  if (!g_FAM) {
    ERROR_LOG("Failed to load FAM!");
    return false;
  }
  if (!g_DEM->IsSpatialMatch(g_FAM)) {
    ERROR_LOG("The spatial characteristics of the DEM and FAM differ!");
    return false;
  }

  if (g_basicConfig->IsESRIDDM()) {
    if (CheckESRIDDM()) {
      ReclassifyDDM();
    } else {
      ERROR_LOG("Was expecting an ESRI Drainage Direction Map and got invalid "
                "values!");
      return false;
    }
  } else {
    if (!CheckSimpleDDM()) {
      ERROR_LOG("Was expecting a simple Drainage Direction Map and got invalid "
                "values!");
      return false;
    }
  }

  FixFAM();

  return true;
}