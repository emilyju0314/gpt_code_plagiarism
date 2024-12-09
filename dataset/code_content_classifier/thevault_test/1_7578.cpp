bool DefaultEffector :: MergeEffects(std::string expr, std::vector<Effect> effects, std::vector<float> results) {
    bool result;

    if (!expr.compare("some(where (p.eft == allow))")) {
        result = false;
        for(unsigned int index = 0 ; index < effects.size() ; index++){
            if (effects[index] == Effect::Allow) {
                result = true;
                break;
            }
        }
    } else if (!expr.compare("!some(where (p.eft == deny))")) {
        result = true;
        for(unsigned int index = 0 ; index < effects.size(); index++){
            if (effects[index] == Effect::Deny) {
                result = false;
                break;
            }
        }
    } else if (!expr.compare("some(where (p.eft == allow)) && !some(where (p.eft == deny))")) {
        result = false;
        for(unsigned int index = 0 ; index < effects.size(); index++){
            if (effects[index] == Effect::Allow) {
                result = true;
            } else if (effects[index] == Effect::Deny) {
                result = false;
                break;
            }
        }
    } else if (!expr.compare("priority(p.eft) || deny")) {
        result = false;
        for(unsigned int index = 0 ; index < effects.size(); index++){
            if (effects[index] != Effect::Indeterminate) {
                if (effects[index] == Effect::Allow) {
                    result = true;
                } else {
                    result = false;
                }
                break;
            }
        }
    } else {
        throw UnsupportedOperationException("unsupported effect");
    }

    return result;
}