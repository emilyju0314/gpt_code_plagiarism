sk_sp<TextAnimator> TextAnimator::Make(const skjson::ObjectValue* janimator,
                                       const AnimationBuilder* abuilder,
                                       AnimatablePropertyContainer* acontainer) {
    if (!janimator) {
        return nullptr;
    }

    const skjson::ObjectValue* jprops = (*janimator)["a"];
    if (!jprops) {
        return nullptr;
    }

    std::vector<sk_sp<RangeSelector>> selectors;

    // Depending on compat mode and whether more than one selector is present,
    // BM exports either an array or a single object.
    if (const skjson::ArrayValue* jselectors = (*janimator)["s"]) {
        selectors.reserve(jselectors->size());
        for (const skjson::ObjectValue* jselector : *jselectors) {
            if (auto sel = RangeSelector::Make(*jselector, abuilder, acontainer)) {
                selectors.push_back(std::move(sel));
            }
        }
    } else {
        if (auto sel = RangeSelector::Make((*janimator)["s"], abuilder, acontainer)) {
            selectors.reserve(1);
            selectors.push_back(std::move(sel));
        }
    }

    return sk_sp<TextAnimator>(
                new TextAnimator(std::move(selectors), *jprops, abuilder, acontainer));
}