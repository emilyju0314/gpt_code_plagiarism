BencEntityMem* BencodedDict::AppendMultiple(char* key, bool allowmultiple) {
	BencEntityMem *slot = NULL;


	if (allowmultiple) { // Possibly populate slot using allowmultiple rules
		slot = (BencEntityMem *) this->Get(key);

		if (slot) { // If there is already a value under that key:
			BencodedList *list = NULL;

			if (slot->bencType == BENC_LIST)
				list = BencEntity::AsList(slot);

			if (!list) { // Entity is not a multiple list yet, so split it out into one
				BencEntity backup;
				backup.MoveFrom( *slot );
				// Null out heap memory pointers so leak asserts don't trigger;
				// a copy of slot was made so should not free resources.
				BencodedList beL;
				slot->MoveFrom(beL);
				list = BencEntity::AsList(slot);	// Transform entity into list

				// Item 0 of the new list is the entity there before
				list->Append(backup);
			}
			BencEntityMem beM;
			slot = (BencEntityMem *) list->Append(beM);
		}
	}

	if (!slot) {// allowmultiple is off, or allowmultiple found nothing present
		BencEntityMem beM;
		slot = (BencEntityMem *) this->Insert(key, -1, beM);
	}

	return slot;
}