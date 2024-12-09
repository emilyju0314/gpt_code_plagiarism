void BlendGraphWidget::AddAnimGraphObjectCategoryMenu(AnimGraphPlugin* plugin, QMenu* parentMenu,
        EMotionFX::AnimGraphObject::ECategory category, EMotionFX::AnimGraphObject* focusedGraphObject)
    {
        // Check if any object of the given category can be created in the currently focused and shown graph.
        bool isEmpty = true;
        const AZStd::vector<EMotionFX::AnimGraphObject*>& objectPrototypes = plugin->GetAnimGraphObjectFactory()->GetUiObjectPrototypes();
        for (EMotionFX::AnimGraphObject* objectPrototype : objectPrototypes)
        {
            if (m_plugin->CheckIfCanCreateObject(focusedGraphObject, objectPrototype, category))
            {
                isEmpty = false;
                break;
            }
        }

        // If the category will be empty, return directly and skip adding a category sub-menu.
        if (isEmpty)
        {
            return;
        }

        const char* categoryName = EMotionFX::AnimGraphObject::GetCategoryName(category);
        QMenu* menu = parentMenu->addMenu(categoryName);

        for (const EMotionFX::AnimGraphObject* objectPrototype : objectPrototypes)
        {
            if (m_plugin->CheckIfCanCreateObject(focusedGraphObject, objectPrototype, category))
            {
                const EMotionFX::AnimGraphNode* nodePrototype = static_cast<const EMotionFX::AnimGraphNode*>(objectPrototype);
                QAction* action = menu->addAction(nodePrototype->GetPaletteName());
                action->setWhatsThis(azrtti_typeid(nodePrototype).ToString<QString>());
                action->setData(QVariant(nodePrototype->GetPaletteName()));
                connect(action, &QAction::triggered, plugin->GetGraphWidget(), &BlendGraphWidget::OnContextMenuCreateNode);
            }
        }
    }