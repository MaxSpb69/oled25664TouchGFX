#include <gui/main_screen/MainView.hpp>

#define MAX_MAIN_MENU_ELEMENTS	3

static uint8_t MenuSelectPosition = 0;
static uint8_t PrevMenuSelectPosition = 10;


MainView::MainView()
{

}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();
    UpdateMenuSelector();

}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::UpdateMenuSelector()
{

	switch(PrevMenuSelectPosition)
	{
	case 0:
		Menu_1_TextArea.setAlpha(96);
		Menu_1_TextArea.invalidate();
		break;
	case 1:
		Menu_2_TextArea.setAlpha(96);
		Menu_2_TextArea.invalidate();
		break;
	case 2:
		Menu_3_TextArea.setAlpha(96);
		Menu_3_TextArea.invalidate();
		break;
	default:
		break;
	}
	switch(MenuSelectPosition)
	{
	case 0:
		Menu_1_TextArea.setAlpha(255);
		Menu_1_TextArea.invalidate();
		break;
	case 1:
		Menu_2_TextArea.setAlpha(255);
		Menu_2_TextArea.invalidate();
		break;
	case 2:
		Menu_3_TextArea.setAlpha(255);
		Menu_3_TextArea.invalidate();
		break;
	default:
		break;
	}
	PrevMenuSelectPosition = MenuSelectPosition;
}


void MainView::MenuNext_Step()
{
	if(MenuSelectPosition < (MAX_MAIN_MENU_ELEMENTS - 1))
	{
		MenuSelectPosition++;
		UpdateMenuSelector();
	}
}

void MainView::MenuPrev_Step()
{
	if(MenuSelectPosition > 0)
	{
		MenuSelectPosition--;
		UpdateMenuSelector();
	}

}

void MainView::MenuSelect()
{
	switch(MenuSelectPosition)
	{
	case 0:
		application().gotoSetValueScreenCoverTransitionWest();
		break;
	case 1:
		application().gotoScreen1ScreenCoverTransitionWest();
		break;
	case 2:
		application().gotoSubMenu1ScreenCoverTransitionWest();
		break;

	default:
		break;
	}

}
