bool recursiveDisplayList(Entity &entity, Entity *& selectedEntity, bool &selectParent, bool editableHierarchy)
		{
			bool modified = false;

			auto cpt = entity->getComponent<AGE::WE::EntityRepresentation>();
			auto archetypeComponent = entity->getComponent<AGE::ArchetypeComponent>();

			bool opened = false;
			opened = ImGui::TreeNode(cpt->name);
			ImGui::PushID(entity.getPtr());
			if (selectedEntity != entity.getPtr())
			{
				if (!selectParent)
				{
					ImGui::SameLine();
					if (ImGui::SmallButton("Select"))
					{
						selectedEntity = entity.getPtr();
					}
				}
				else if (editableHierarchy && archetypeComponent == nullptr)
				{
					ImGui::SameLine();
					if (ImGui::SmallButton("Set as parent"))
					{
						modified = true;
						(*selectedEntity)->getLink().attachParent(entity.getLinkPtr());
						selectParent = false;
					}
				}
			}
			else
			{
				auto canChangeHierarchy = archetypeComponent == nullptr || (archetypeComponent->parentIsAnArchetype == false);
				if (!selectParent && editableHierarchy && canChangeHierarchy)
				{
					ImGui::SameLine();
					if (ImGui::SmallButton("Set parent"))
					{
						selectParent = true;
					}
				}
				else if (editableHierarchy && canChangeHierarchy)
				{
					ImGui::SameLine();
					if (ImGui::SmallButton("Root"))
					{
						modified = true;
						(*selectedEntity)->getLink().detachParent();
						selectParent = false;
					}
					ImGui::SameLine();
					if (ImGui::SmallButton("Cancel"))
					{
						selectParent = false;
					}
				}
			}
			ImGui::PopID();
			if (opened)
			{
				if (entity->getLink().hasChildren())
				{
					auto children = entity->getLink().getChildren();
					for (auto &e : children)
					{
						if (recursiveDisplayList(e->getEntity()->getEntity(), selectedEntity, selectParent, editableHierarchy))
						{
							modified = true;
						}
					}
				}
				ImGui::TreePop();
			}
			return modified;
		}