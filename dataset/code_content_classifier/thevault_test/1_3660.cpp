FOR_EACH_VEC( vecEquipRegionNames, i )
		{
			const char *pszEquipRegionName = vecEquipRegionNames[i];
			equip_region_mask_t unThisRegionMask = pschema.GetEquipRegionMaskByName( pszEquipRegionName );

			SCHEMA_INIT_CHECK(
				unThisRegionMask != 0,
				CFmtStr( "Item definition %s: Unable to find equip region mask for region named \"%s\"", GetDefinitionName(), vecEquipRegionNames[i] ) );

			m_unEquipRegionMask |= pschema.GetEquipRegionBitMaskByName( pszEquipRegionName );
			m_unEquipRegionConflictMask |= unThisRegionMask;
		}