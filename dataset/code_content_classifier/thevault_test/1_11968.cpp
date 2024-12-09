static void EnableViewPaneDisabledGraphicsEffect(QWidget* widget)
    {
        // only apply effects to widgets that didn't have them already...
        if (widget->graphicsEffect() == nullptr)
        {
            auto effect = AZStd::make_unique<QGraphicsOpacityEffect>();
            effect->setOpacity(s_disabledPaneOpacity);
            // flag this as our effect so we can get rid of it later
            effect->setProperty(s_viewPaneManagerDisableEffectPropertyName, true);

            widget->setGraphicsEffect(effect.release());

            // ensure the widget is redrawn with the updated graphical effect
            ForceWidgetRedraw(widget);
        }
    }