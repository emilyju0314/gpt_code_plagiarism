ProjectItem::ProjectItem(QList<TemplateList *> templates) {
    setTextColor(Qt::black);
    setEditable(false);
    setTemplates();
    foreach (TemplateList *templateList, templates) {
      appendRow( new ProjectItem(templateList) );
    }
  }