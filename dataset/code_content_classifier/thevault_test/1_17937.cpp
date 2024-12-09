auto ProfileSelectorWidget::updateComboBox(int index) noexcept -> void
{
        QStringList qlist;
        qlist << "Add new profile";
        for(auto e : pw.listRunningProcs())
                qlist << QString(e.c_str());

        // if we selected some new profile name from list
        if(index)
        {
                QString name(profileList.itemText(index));
                // TODO: dynamically add icon instead of using this default
                QIcon icon(":/resources/xclient.svg");
                cfg.setDVC(name, dvc_map);
                cfg.setIconPath(name, ":/resources/xclient.svg");
                tabs.addTab(new AppProfile(name, this), icon, name);
        }

        // remove items that are already in cfg from the list of potential new app profiles
        for(auto &e : cfg.queryProfiles())
        {
                qlist.removeOne(QString(e));
        }

        profileList.clear();
        profileList.addItems(qlist);
}