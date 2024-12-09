void collectContent(const AstComponent& component, const TypeBinding& binding,
        const AstComponent* enclosingComponent, const ComponentLookup& componentLookup, ComponentContent& res,
        std::vector<std::unique_ptr<AstClause>>& orphans, const std::set<std::string>& overridden,
        ErrorReport& report, unsigned int maxInstantiationDepth) {
    // start with relations and clauses of the base components
    for (const auto& base : component.getBaseComponents()) {
        const AstComponent* comp = componentLookup.getComponent(enclosingComponent, base->getName(), binding);
        if (comp) {
            // link formal with actual type parameters
            const auto& formalParams = comp->getComponentType()->getTypeParameters();
            const auto& actualParams = base->getTypeParameters();

            // update type binding
            TypeBinding activeBinding = binding.extend(formalParams, actualParams);

            for (const auto& cur : comp->getInstantiations()) {
                // instantiate sub-component
                ComponentContent content = getInstantiatedContent(*cur, enclosingComponent, componentLookup,
                        orphans, report, activeBinding, maxInstantiationDepth - 1);

                // process types
                for (auto& type : content.types) {
                    res.add(type, report);
                }

                // process relations
                for (auto& rel : content.relations) {
                    res.add(rel, report);
                }

                // process io directives
                for (auto& io : content.loads) {
                    res.add(io, report);
                }
                for (auto& io : content.printSizes) {
                    res.add(io, report);
                }
                for (auto& io : content.stores) {
                    res.add(io, report);
                }
            }

            // collect definitions from base type
            std::set<std::string> superOverridden;
            superOverridden.insert(overridden.begin(), overridden.end());
            superOverridden.insert(component.getOverridden().begin(), component.getOverridden().end());
            collectContent(*comp, activeBinding, comp, componentLookup, res, orphans, superOverridden, report,
                    maxInstantiationDepth);
        }
    }

    // and continue with the local types
    for (const auto& cur : component.getTypes()) {
        // create a clone
        std::unique_ptr<AstType> type(cur->clone());

        // instantiate elements of union types
        visitDepthFirst(*type, [&](const AstUnionType& type) {
            for (const auto& name : type.getTypes()) {
                AstTypeIdentifier newName = binding.find(name);
                if (!newName.empty()) {
                    const_cast<AstTypeIdentifier&>(name) = newName;
                }
            }
        });

        // instantiate elements of record types
        visitDepthFirst(*type, [&](const AstRecordType& type) {
            for (const auto& field : type.getFields()) {
                AstTypeIdentifier newName = binding.find(field.type);
                if (!newName.empty()) {
                    const_cast<AstTypeIdentifier&>(field.type) = newName;
                }
            }
        });

        // add to result list (check existence first)
        res.add(type, report);
    }

    // and the local relations
    for (const auto& cur : component.getRelations()) {
        // create a clone
        std::unique_ptr<AstRelation> rel(cur->clone());

        // update attribute types
        for (AstAttribute* attr : rel->getAttributes()) {
            AstTypeIdentifier forward = binding.find(attr->getTypeName());
            if (!forward.empty()) {
                attr->setTypeName(forward);
            }
        }

        // add to result list (check existence first)
        res.add(rel, report);
    }

    // and the local io directives
    for (const auto& cur : component.getLoads()) {
        // create a clone
        std::unique_ptr<AstLoad> io(cur->clone());

        res.add(io, report);
    }
    for (const auto& cur : component.getPrintSizes()) {
        // create a clone
        std::unique_ptr<AstPrintSize> io(cur->clone());

        res.add(io, report);
    }
    for (const auto& cur : component.getStores()) {
        // create a clone
        std::unique_ptr<AstStore> io(cur->clone());

        res.add(io, report);
    }

    // index the available relations
    std::map<AstRelationIdentifier, AstRelation*> index;
    for (const auto& cur : res.relations) {
        index[cur->getName()] = cur.get();
    }

    // add the local clauses
    for (const auto& cur : component.getClauses()) {
        if (overridden.count(cur->getHead()->getName().getNames()[0]) == 0) {
            AstRelation* rel = index[cur->getHead()->getName()];
            if (rel) {
                rel->addClause(std::unique_ptr<AstClause>(cur->clone()));
            } else {
                orphans.emplace_back(cur->clone());
            }
        }
    }

    // add orphan clauses at the current level if they can be resolved
    for (auto iter = orphans.begin(); iter != orphans.end();) {
        auto& cur = *iter;
        AstRelation* rel = index[cur->getHead()->getName()];
        if (rel) {
            // add orphan to current instance and delete from orphan list
            rel->addClause(std::unique_ptr<AstClause>(cur->clone()));
            iter = orphans.erase(iter);
        } else {
            ++iter;
        }
    }
}