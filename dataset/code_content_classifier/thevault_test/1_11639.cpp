QSize NotificationListViewDelegate::sizeHint(const QStyleOptionViewItem &  option ,
                              const QModelIndex & index) const
{
    QSize iconsize = QSize(20,20);
    QFont font = QApplication::font();
    QFontMetrics fm(font);

    return(QSize(iconsize.width(),iconsize.height()+fm.height() + 8));
}