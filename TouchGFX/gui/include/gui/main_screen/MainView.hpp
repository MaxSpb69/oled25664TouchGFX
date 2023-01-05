#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>


class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void MenuNext_Step();
    virtual void MenuPrev_Step();
    virtual void MenuSelect();


protected:
    virtual void UpdateMenuSelector();

};

#endif // MAINVIEW_HPP
