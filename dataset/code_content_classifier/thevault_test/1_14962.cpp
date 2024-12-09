void InitFloristOrderForm()
{
	gfFLoristCheckBox0Down = FALSE; // next day delviery
	gfFLoristCheckBox1Down = TRUE; // when it gets there delivery
	gfFLoristCheckBox2Down = FALSE;
	gfFLoristCheckBox3Down = FALSE;
	gfFLoristCheckBox4Down = FALSE;
	gfFLoristCheckBox5Down = FALSE;

	guiFlowerPrice = 0;

	gubCurrentlySelectedFlowerLocation = 0;
	gbCurrentlySelectedCard = -1;

	gsSentimentTextField = ST::null;
	gsNameTextField = ST::null;
}