static void ChooseWeaponForSoldierCreateStruct(SOLDIERCREATE_STRUCT* pp, INT8 bWeaponClass, INT8 bAmmoClips, INT8 bAttachClass, BOOLEAN fAttachment)
{
	OBJECTTYPE Object;
	UINT16 i;
	UINT16 usRandom;
	UINT16 usNumMatches = 0;
	UINT16 usGunIndex = 0;
	UINT16 usAmmoIndex = 0;
	UINT16 usAttachIndex = 0;
	UINT8 ubChanceStandardAmmo;
	INT8 bStatus;

	// Choose weapon:
	// WEAPONS are very important, and are therefore handled differently using special pre-generated tables.
	// It was requested that enemies use only a small subset of guns with a lot duplication of the same gun type.

	// if gun was pre-selected (rcvd negative weapon class) and needs ammo
	if( bWeaponClass < 0 && bAmmoClips )
	{
		//Linda has added a specific gun to the merc's inventory, but no ammo.  So, we
		//will choose ammunition that works with the gun.
		for( i = 0; i < NUM_INV_SLOTS; i++ )
		{
			if( GCM->getItem(pp->Inv[ i ].usItem)->getItemClass() == IC_GUN )
			{
				usGunIndex = pp->Inv[ i ].usItem;
				ubChanceStandardAmmo = 100 - (bWeaponClass * -9);		// weapon class is negative!
				usAmmoIndex = RandomMagazine( usGunIndex, ubChanceStandardAmmo );

				if ( usGunIndex == ROCKET_RIFLE )
				{
					pp->Inv[ i ].ubImprintID = (NO_PROFILE + 1);
				}

				break;
			}
		}
		if( bAmmoClips && usAmmoIndex )
		{
			CreateItems( usAmmoIndex, 100, bAmmoClips, &Object );
			Object.fFlags |= OBJECT_UNDROPPABLE;
			PlaceObjectInSoldierCreateStruct( pp, &Object );
		}

		return;
	}

	if (bWeaponClass < 1)
		return; //empty handed / pre-selected

	// reduce anything over 11 to 11
	if (bWeaponClass > ARMY_GUN_LEVELS)
	{
		bWeaponClass = ARMY_GUN_LEVELS;
	}


	// the weapon class here ranges from 1 to 11, so subtract 1 to get a gun level
	usGunIndex = SelectStandardArmyGun( (UINT8) (bWeaponClass - 1));


	if( bAmmoClips )
	{
		//We have a gun, so choose ammo clips

		// check default ammo first...
		usAmmoIndex = DefaultMagazine( usGunIndex );
		switch( GCM->getItem(usAmmoIndex)->asAmmo()->ammoType->index )
		{
			case AMMO_AP:
			case AMMO_SUPER_AP:
				// assault rifle, rocket rifle (etc) - high chance of having AP ammo
				ubChanceStandardAmmo = 80;
				break;
			default:
				ubChanceStandardAmmo = 100 - (bWeaponClass * 9);
				break;
		}
		usAmmoIndex = RandomMagazine( usGunIndex, ubChanceStandardAmmo );
	}

	//Choose attachment
	if( bAttachClass && fAttachment )
	{
		usNumMatches = 0;
		while( bAttachClass && !usNumMatches )
		{
			//Count the number of valid attachments.
			for( i = 0; i < MAXITEMS; i++ )
			{
				const ItemModel * pItem = GCM->getItem(i);
				if( pItem->getItemClass() == IC_MISC && pItem->getCoolness() == bAttachClass && ValidAttachment( i, usGunIndex ) )
					usNumMatches++;
			}
			if( !usNumMatches )
			{
				bAttachClass--;
			}
		}
		if( usNumMatches )
		{
			usRandom = (UINT16)Random( usNumMatches );
			for( i = 0; i < MAXITEMS; i++ )
			{
				const ItemModel * pItem = GCM->getItem(i);
				if( pItem->getItemClass() == IC_MISC && pItem->getCoolness() == bAttachClass && ValidAttachment( i, usGunIndex ) )
				{
					if( usRandom )
						usRandom--;
					else
					{
						usAttachIndex = i;
						break;
					}
				}
			}
		}
	}
	//Now, we have chosen all of the correct items.  Now, we will assign them into the slots.
	//Because we are dealing with enemies, automatically give them full ammo in their weapon.
	if( !(pp->Inv[ HANDPOS ].fFlags & OBJECT_NO_OVERWRITE) )
	{
		switch( pp->ubSoldierClass )
		{
			case SOLDIER_CLASS_ADMINISTRATOR:
			case SOLDIER_CLASS_ARMY:
			case SOLDIER_CLASS_GREEN_MILITIA:
			case SOLDIER_CLASS_REG_MILITIA:
				//Admins/Troops: 60-75% + 1% every 4% progress
				bStatus = (INT8)(60 + Random( 16 ));
				bStatus += (INT8)(HighestPlayerProgressPercentage() / 4);
				bStatus = (INT8)MIN( 100, bStatus );
				break;
			case SOLDIER_CLASS_ELITE:
			case SOLDIER_CLASS_ELITE_MILITIA:
				//85-90% +  1% every 10% progress
				bStatus = (INT8)(85 + Random( 6 ));
				bStatus += (INT8)(HighestPlayerProgressPercentage() / 10);
				bStatus = (INT8)MIN( 100, bStatus );
				break;
			default:
				bStatus = (INT8)(50 + Random( 51 ) );
				break;
		}
		// don't allow it to be lower than marksmanship, we don't want it to affect their chances of hitting
		bStatus = (INT8)MAX( pp->bMarksmanship, bStatus );

		bStatus = (INT8)MAX( bStatus, gamepolicy(enemy_weapon_minimal_status));

		CreateItem( usGunIndex, bStatus, &(pp->Inv[ HANDPOS ]) );
		pp->Inv[ HANDPOS ].fFlags |= OBJECT_UNDROPPABLE;

		// Rocket Rifles must come pre-imprinted, in case carrier gets killed without getting a shot off
		if ( usGunIndex == ROCKET_RIFLE )
		{
			pp->Inv[ HANDPOS ].ubImprintID = (NO_PROFILE + 1);
		}
	}
	else
	{
		//slot locked, so don't add any attachments to it!
		usAttachIndex = 0;
	}
	//Ammo
	if( bAmmoClips && usAmmoIndex )
	{
		CreateItems( usAmmoIndex, 100, bAmmoClips, &Object );
		Object.fFlags |= OBJECT_UNDROPPABLE;
		PlaceObjectInSoldierCreateStruct( pp, &Object );
	}
	if( usAttachIndex )
	{
		CreateItem( usAttachIndex, 100, &Object );
		Object.fFlags |= OBJECT_UNDROPPABLE;
		AttachObject( NULL, &(pp->Inv[ HANDPOS ]), &Object );
	}
}