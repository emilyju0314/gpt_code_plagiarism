void COptionVarList::PerformLayout()
{
	int wide, tall;
	GetSize( wide, tall );

	int vpixels = computeVPixelsNeeded();
	int yScaled = 150;

	//!! need to make it recalculate scroll positions
	_vbar->SetVisible(true);
	_vbar->SetEnabled(false);
	_vbar->SetBgColor(Color(0, 0, 0, 0));
	_vbar->GetSlider()->SetBgColor(Color(0, 0, 0, 0));
	_vbar->SetBorder(nullptr);
	_vbar->SetScrollbarButtonsVisible(false);
	_vbar->UseImages(nullptr, nullptr, nullptr, nullptr);
	_vbar->SetRange( 0, vpixels - tall + vgui::scheme()->GetProportionalScaledValue( yScaled ) );
	_vbar->SetRangeWindow( vgui::scheme()->GetProportionalScaledValue( yScaled ) /*vpixels / 10*/ );
	_vbar->SetButtonPressedScrollValue( vgui::scheme()->GetProportionalScaledValue( yScaled ) );
	_vbar->SetPos(wide - 20, _sliderYOffset);
	_vbar->SetSize(18, tall - 2 - _sliderYOffset);
	_vbar->InvalidateLayout();

	int top = _vbar->GetValue();

	_embedded->SetPos( 0, -top );
	_embedded->SetSize( wide-20, vpixels );

	// Now lay out the controls on the embedded panel
	int y = 0;
	int h = 0;
	for ( int i = 0; i < _dataItems.GetCount(); i++, y += h )
	{
		DATAITEM *item = _dataItems[ i ];
		if ( !item || !item->panel )
			continue;

		h = item->panel->GetTall();
		item->panel->SetBounds( 8, y, wide-36, h );
	}
}