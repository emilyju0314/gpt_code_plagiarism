FOR_EACH(BUTTON_PICS, other, ButtonPictures)
		{
			if (other == pics) continue;
			if (other->vobj != pics->vobj) continue;
			if (!(other->fFlags & GUI_BTN_DUPLICATE_VOBJ)) continue;

			/* If we got here, then we got a duplicate object of the one we want to
			 * delete, so convert it to an original!
			 */
			other->fFlags &= ~GUI_BTN_DUPLICATE_VOBJ;

			// Now remove this button, but not its vobject
			goto remove_pic;
		}