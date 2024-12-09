FOR_EACH_GROUP(curr)
			{
				if (gubNumGroupsArrivedSimultaneously == 0) break;
				if( curr->uiFlags & GROUPFLAG_GROUP_ARRIVED_SIMULTANEOUSLY )
				{
					curr->uiFlags &= ~GROUPFLAG_GROUP_ARRIVED_SIMULTANEOUSLY;
					gubNumGroupsArrivedSimultaneously--;
				}
			}