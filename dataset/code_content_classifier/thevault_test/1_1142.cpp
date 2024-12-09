foreach (QVariant image, newImagesList) {
            QVariantMap imageMap = image.toMap();
            FacebookPhotoImageInterface *imageInterface = new FacebookPhotoImageInterface(q);
            qobject_cast<FacebookInterface*>(q->socialNetwork())->setFacebookContentItemData(imageInterface, imageMap);
            images.append(imageInterface);
        }