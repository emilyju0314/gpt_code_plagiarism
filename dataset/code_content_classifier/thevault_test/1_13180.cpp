static ButtonEvent *toCType(const unsigned short buttonevent, Napi::Object src) {
    ButtonEvent * result = new ButtonEvent();

    Napi::Array buttonEventInfo = src.Get("buttonEventInfo").As<Napi::Array>();
    if (buttonEventInfo.IsArray()) {
        result->buttonEventCount = util::getObjInt32OrDefault(buttonEventInfo, "buttonEventCount", 0);
        result->buttonEventInfo = new ButtonEventInfo[result->buttonEventCount];

        for ( int i=0; i<result->buttonEventCount; ++i) {
            ButtonEventInfo& btnEventDst = result->buttonEventInfo[i];
            Napi::Object btnEventSrc = buttonEventInfo.Get(i).ToObject();

            btnEventDst.buttonTypeKey = util::getObjInt32OrDefault(btnEventSrc, "buttonTypeKey", -1);
            btnEventDst.buttonTypeValue = newCString(btnEventSrc.Get("buttonTypeValue"));
            btnEventDst.buttonEventTypeSize = util::getObjInt32OrDefault(btnEventSrc, "buttonEventTypeSize", -1);
            btnEventDst.buttonEventType = new ButtonEventType[btnEventDst.buttonEventTypeSize];

            Napi::Array buttonEventTypeArray = btnEventSrc.Get("buttonEventType").As<Napi::Array>();
            if (buttonEventTypeArray.IsArray()) {
                for (int j=0; j<btnEventDst.buttonEventTypeSize; ++j) {
                    ButtonEventType& btnEventTypeDst = btnEventDst.buttonEventType[j];
                    Napi::Object btnEventTypeSrcObj = buttonEventTypeArray.Get(j).As<Napi::Object>();

                    btnEventTypeDst.key = util::getObjInt32OrDefault(btnEventTypeSrcObj, "key", 0);
                    btnEventTypeDst.value = newCString(btnEventTypeSrcObj.Get("value"));
                }
            } else {
                btnEventDst.buttonEventTypeSize = 0;
                btnEventDst.buttonEventType = nullptr;
            }
        }
    } else {
        result->buttonEventCount = 0;
        result->buttonEventInfo = nullptr;
    }

    return result;
}