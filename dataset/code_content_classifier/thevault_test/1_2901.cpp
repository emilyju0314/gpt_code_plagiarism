void PropertyMap::addProperty(
    Term key, Symbol property, unsigned ruleID) {
  assert(property.isProperty());
  assert(*System.getRule(ruleID).isPropertyRule() == property);
  auto *props = getOrCreateProperties(key);
  bool debug = Debug.contains(DebugFlags::ConcreteUnification);

  switch (property.getKind()) {
  case Symbol::Kind::Protocol:
    props->ConformsTo.push_back(property.getProtocol());
    props->ConformsToRules.push_back(ruleID);
    return;

  case Symbol::Kind::Layout: {
    auto newLayout = property.getLayoutConstraint();

    if (!props->Layout) {
      // If we haven't seen a layout requirement before, just record it.
      props->Layout = newLayout;
      props->LayoutRule = ruleID;
    } else {
      // Otherwise, compute the intersection.
      assert(props->LayoutRule.hasValue());
      auto mergedLayout = props->Layout.merge(property.getLayoutConstraint());

      // If the intersection is invalid, we have a conflict.
      if (!mergedLayout->isKnownLayout()) {
        recordConflict(key, *props->LayoutRule, ruleID, System);
        return;
      }

      // If the intersection is equal to the existing layout requirement,
      // the new layout requirement is redundant.
      if (mergedLayout == props->Layout) {
        if (checkRulePairOnce(*props->LayoutRule, ruleID)) {
          recordRelation(key, *props->LayoutRule, property, System, debug);
        }

      // If the intersection is equal to the new layout requirement, the
      // existing layout requirement is redundant.
      } else if (mergedLayout == newLayout) {
        if (checkRulePairOnce(ruleID, *props->LayoutRule)) {
          auto oldProperty = System.getRule(*props->LayoutRule).getLHS().back();
          recordRelation(key, ruleID, oldProperty, System, debug);
        }

        props->LayoutRule = ruleID;
      } else {
        llvm::errs() << "Arbitrary intersection of layout requirements is "
                     << "supported yet\n";
        abort();
      }
    }

    return;
  }

  case Symbol::Kind::Superclass: {
    if (checkRuleOnce(ruleID)) {
      // A rule (T.[superclass: C] => T) induces a rule (T.[layout: L] => T),
      // where L is either AnyObject or _NativeObject.
      auto superclass =
          property.getConcreteType()->getClassOrBoundGenericClass();
      auto layout =
          LayoutConstraint::getLayoutConstraint(
            superclass->getLayoutConstraintKind(),
            Context.getASTContext());
      auto layoutSymbol = Symbol::forLayout(layout, Context);

      recordRelation(key, ruleID, layoutSymbol, System, debug);
    }

    if (!props->Superclass) {
      props->Superclass = property;
      props->SuperclassRule = ruleID;
    } else {
      assert(props->SuperclassRule.hasValue());
      auto pair = unifySuperclasses(*props->Superclass, property,
                                    System, debug);
      props->Superclass = pair.first;
      bool conflict = pair.second;
      if (conflict) {
        recordConflict(key, *props->SuperclassRule, ruleID, System);
        return;
      }
    }

    return;
  }

  case Symbol::Kind::ConcreteType: {
    if (!props->ConcreteType) {
      props->ConcreteType = property;
      props->ConcreteTypeRule = ruleID;
    } else {
      assert(props->ConcreteTypeRule.hasValue());
      bool conflict = unifyConcreteTypes(*props->ConcreteType, property,
                                         System, debug);
      if (conflict) {
        recordConflict(key, *props->ConcreteTypeRule, ruleID, System);
        return;
      }
    }

    return;
  }

  case Symbol::Kind::ConcreteConformance:
    // FIXME
    return;

  case Symbol::Kind::Name:
  case Symbol::Kind::GenericParam:
  case Symbol::Kind::AssociatedType:
    break;
  }

  llvm_unreachable("Bad symbol kind");
}