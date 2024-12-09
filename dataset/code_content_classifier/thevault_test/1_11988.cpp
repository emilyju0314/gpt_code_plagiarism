QSize AZAutoSizingScrollArea::sizeHint() const
    {
        int initialSize = 2 * frameWidth();
        QSize sizeHint(initialSize, initialSize);
        
        if (widget())
        {
            sizeHint += this->widgetResizable() ? widget()->sizeHint() : widget()->size();
        }
        else
        {
            // If we don't have a widget, we want to reserve some space visually for ourselves.            
            int fontHeight = fontMetrics().height();
            sizeHint += QSize(2 * fontHeight, 2 * fontHeight);
        }

        if (verticalScrollBarPolicy() == Qt::ScrollBarAlwaysOn)
        {
            sizeHint.setWidth(sizeHint.width() + verticalScrollBar()->sizeHint().width());
        }

        if (horizontalScrollBarPolicy() == Qt::ScrollBarAlwaysOn)
        {
            sizeHint.setHeight(sizeHint.height() + horizontalScrollBar()->sizeHint().height());
        }

        return sizeHint;
    }