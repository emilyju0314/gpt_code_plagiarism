foreach (QVariant tag, newTagsList) {
            QVariantMap tagMap = tag.toMap();
            FacebookPhotoTagInterface *tagInterface = new FacebookPhotoTagInterface(q);
            qobject_cast<FacebookInterface*>(q->socialNetwork())->setFacebookContentItemData(tagInterface, tagMap);
            tags.append(tagInterface);
        }