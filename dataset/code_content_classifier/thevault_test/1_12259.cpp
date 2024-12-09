AZ::Vector3 GetTranslationForSelectedElement(const AZ::EntityId& activeElementId,
        AZ::Entity* selectedElement,
        const AZ::Vector3& mouseTranslation)
    {
        // When the user is interacting with an element (the "ACTIVE" element),
        // the interaction will usually also affect every other SELECTED element.
        // This function does the work to find the mouse translation vector
        // with respect to the ACTIVE element, oriented with respect to the
        // SELECTED element in question, with the same length as the original
        // mouse translation vector. The resulting vector is in viewport space.

        // Find the orientation of the translation vector from the ACTIVE element's
        // perspective.
        AZ::Matrix4x4 activeTransformFromViewport;
        EBUS_EVENT_ID(activeElementId, UiTransformBus, GetTransformFromViewport, activeTransformFromViewport);
        AZ::Vector3 activeElementTranslation = activeTransformFromViewport.Multiply3x3(mouseTranslation);

        // Give the translation vector the same orientation with respect to
        // the SELECTED element that it had with respect to the ACTIVE element.
        AZ::Matrix4x4 selectedTransformToViewport;
        EBUS_EVENT_ID(selectedElement->GetId(), UiTransformBus, GetTransformToViewport, selectedTransformToViewport);
        AZ::Vector3 elementViewportTranslation = selectedTransformToViewport.Multiply3x3(activeElementTranslation);

        // Adjust the translation vector to have the same length as the original
        // viewport-space translation vector.
        return elementViewportTranslation.GetNormalizedSafe() * mouseTranslation.GetLength();
    }