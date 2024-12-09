static void RecursiveKeyLoop(KeyValues *pBlock, void *pCustom, IVPhysicsKeyHandler *unknownKeyHandler) {
	for (KeyValues *pKey = pBlock; pKey; pKey = pKey->GetNextKey()) {
		const char *key = pKey->GetName();
		const char *value = pKey->GetString();
		unknownKeyHandler->ParseKeyValue(pCustom, key, value);

		// Recurse
		if (pKey->GetFirstSubKey())
			RecursiveKeyLoop(pKey->GetFirstSubKey(), pCustom, unknownKeyHandler);
	}
}