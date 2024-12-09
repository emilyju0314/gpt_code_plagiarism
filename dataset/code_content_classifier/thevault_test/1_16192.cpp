void RestoreButtonText() {
        getLogger().info("Restoring changed button text . . .");
        for(auto& entry : previousButtonText) {
            // Change the text back to what it was
            TextMeshProUGUI* textMesh = entry.first->GetComponentInChildren<TextMeshProUGUI*>();
            textMesh->set_text(il2cpp_utils::createcsstr(entry.second));
        }
        previousButtonText.clear(); // Empty the map - no buttons are overridden
    }