static void DisableViewPaneDisabledGraphicsEffect(QWidget* widget)
    {
        // only remove effects from widgets that we added them to
        QGraphicsEffect* effect = widget->graphicsEffect();
        if (effect != nullptr && !effect->property(s_viewPaneManagerDisableEffectPropertyName).isNull())
        {
            widget->setGraphicsEffect(nullptr);
        }
    }