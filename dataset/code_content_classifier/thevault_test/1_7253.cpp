OSStatus HandleMenu( HICommand *cmd )
{
  OSStatus ret = eventNotHandledErr;
  // attributes, commandIDm menu.menuRef, menu.menuItemIndex
  UInt32 ref;
  OSErr rrc = GetMenuItemRefCon( cmd->menu.menuRef, cmd->menu.menuItemIndex, &ref );
  //printf( "%d, %08x, %08x, %d, %d, %8x\n", rrc, cmd->attributes, cmd->commandID, cmd->menu.menuRef, cmd->menu.menuItemIndex, rrc );
  if ( rrc==noErr && ref )
  {
    Fl_Menu_Item *m = (Fl_Menu_Item*)ref;
    //printf( "Menu: %s\n", m->label() );
    fl_sys_menu_bar->picked( m );
    if ( m->flags & FL_MENU_TOGGLE ) // update the menu toggle symbol
      SetItemMark( cmd->menu.menuRef, cmd->menu.menuItemIndex, (m->flags & FL_MENU_VALUE ) ? 0x12 : 0 );
    if ( m->flags & FL_MENU_RADIO ) // update all radio buttons in this menu
    {
      Fl_Menu_Item *j = m;
      int i = cmd->menu.menuItemIndex;
      for (;;)
      {
        if ( j->flags & FL_MENU_DIVIDER )
          break;
        j++; i++;
        if ( !j->text || !j->radio() )
          break;
        SetItemMark( cmd->menu.menuRef, i, ( j->flags & FL_MENU_VALUE ) ? 0x13 : 0 );
      }
      j = m-1; i = cmd->menu.menuItemIndex-1;
      for ( ; i>0; j--, i-- )
      {
        if ( !j->text || j->flags&FL_MENU_DIVIDER || !j->radio() )
          break;
        SetItemMark( cmd->menu.menuRef, i, ( j->flags & FL_MENU_VALUE ) ? 0x13 : 0 );
      }
      SetItemMark( cmd->menu.menuRef, cmd->menu.menuItemIndex, ( m->flags & FL_MENU_VALUE ) ? 0x13 : 0 );
    }
    ret = noErr; // done handling this event
  }
  HiliteMenu(0);
  return ret;
}