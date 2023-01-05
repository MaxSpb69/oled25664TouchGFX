#include <gui/submenu1_screen/SubMenu1View.hpp>

#define MENU_ITEM_HEIGHT	18
#define MENU_ITEMS			6
#define X_MENU_POSITION	    64

static int16_t MenuPosition;

SubMenu1View::SubMenu1View()
{

}

void SubMenu1View::setupScreen()
{
    SubMenu1ViewBase::setupScreen();
    MenuPosition = 0;
   // ListMenu_container.setPosition(64, 18, 64, 113);
}

void SubMenu1View::tearDownScreen()
{
    SubMenu1ViewBase::tearDownScreen();
}

void SubMenu1View::ScrollMenuDown()
{
	if(MenuPosition < (MENU_ITEMS - 1))
	{
		MenuPosition++;
		ListMenu_container.clearMoveAnimationEndedAction();
		ListMenu_container.startMoveAnimation(X_MENU_POSITION, MENU_ITEM_HEIGHT - (MenuPosition * MENU_ITEM_HEIGHT), 3, touchgfx::EasingEquations::cubicEaseIn, touchgfx::EasingEquations::cubicEaseIn);


	}
}

void SubMenu1View::ScrollMenuUp()
{
	if(MenuPosition > 0)
	{
		MenuPosition--;
		ListMenu_container.clearMoveAnimationEndedAction();
		ListMenu_container.startMoveAnimation(X_MENU_POSITION, MENU_ITEM_HEIGHT - (MenuPosition * MENU_ITEM_HEIGHT), 3, touchgfx::EasingEquations::cubicEaseIn, touchgfx::EasingEquations::cubicEaseIn);
	}

}

void SubMenu1View::MenuSelect()
{
	switch(MenuPosition)
	{
	case 5:
		application().gotoMainScreenCoverTransitionEast();
		break;
	default:
		break;
	}
}
