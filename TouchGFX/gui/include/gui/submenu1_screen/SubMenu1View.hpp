#ifndef SUBMENU1VIEW_HPP
#define SUBMENU1VIEW_HPP

#include <gui_generated/submenu1_screen/SubMenu1ViewBase.hpp>
#include <gui/submenu1_screen/SubMenu1Presenter.hpp>

class SubMenu1View : public SubMenu1ViewBase
{
public:
    SubMenu1View();
    virtual ~SubMenu1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void ScrollMenuDown();
    virtual void ScrollMenuUp();
    virtual void MenuSelect();
protected:
};

#endif // SUBMENU1VIEW_HPP
