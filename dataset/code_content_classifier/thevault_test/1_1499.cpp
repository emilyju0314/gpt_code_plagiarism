void ProjectItem::setTemplateList(TemplateList *templateList) {
    setTextColor(Qt::black);
    if (templateList->name() != "") {
      setText( templateList->name() );
    }
    else {
      setText( templateList->path() );
    }
    setIcon( QIcon(FileName("$ISISROOT/appdata/images/icons/folder-orange.png")
                           .expanded()));
    setData( QVariant::fromValue<TemplateList *>(templateList) );
  }