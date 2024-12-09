void AttachmentsWindow::dropEvent(QDropEvent* event)
    {
        // check if we dropped any files to the application
        const QMimeData* mimeData = event->mimeData();
        if (mimeData->hasUrls())
        {
            // read out the dropped file names
            const QList<QUrl> urls = mimeData->urls();

            // clear the drop filenames
            m_dropFileNames.clear();
            m_dropFileNames.reserve(urls.count());

            // get the number of urls and iterate over them
            AZStd::string filename;
            AZStd::string extension;
            const int numUrls = urls.count();
            for (int i = 0; i < numUrls; ++i)
            {
                // get the complete file name and extract the extension
                filename = urls[i].toLocalFile().toUtf8().data();
                AzFramework::StringFunc::Path::GetExtension(filename.c_str(), extension, false /* include dot */);

                if (extension == "actor")
                {
                    m_dropFileNames.push_back(filename);
                }
            }

            // get the number of dropped sound files
            if (m_dropFileNames.empty())
            {
                MCore::LogWarning("Drag and drop failed. No valid actor file dropped.");
            }
            else
            {
                // create the import context menu
                QMenu menu(this);

                QAction* attachmentAction   = menu.addAction("Open Regular Attachment");
                QAction* deformableAction   = menu.addAction("Open Skin Attachment");
                menu.addSeparator();
                /*QAction* cancelAction     =*/menu.addAction("Cancel");

                connect(attachmentAction, &QAction::triggered, this, &AttachmentsWindow::OnDroppedAttachmentsActors);
                connect(deformableAction, &QAction::triggered, this, &AttachmentsWindow::OnDroppedDeformableActors);

                // show the menu at the given position
                menu.exec(mapToGlobal(event->pos()));
            }
        }

        event->acceptProposedAction();
    }