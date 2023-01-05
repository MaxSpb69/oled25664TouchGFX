/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    virtual void changeToStartScreen()
    {
        gotoMainScreenNoTransition();
    }

    // Main
    void gotoMainScreenNoTransition();

    void gotoMainScreenCoverTransitionEast();

    // SetValue
    void gotoSetValueScreenCoverTransitionWest();

    // Screen1
    void gotoScreen1ScreenCoverTransitionWest();

    // SubMenu1
    void gotoSubMenu1ScreenCoverTransitionWest();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Main
    void gotoMainScreenNoTransitionImpl();

    void gotoMainScreenCoverTransitionEastImpl();

    // SetValue
    void gotoSetValueScreenCoverTransitionWestImpl();

    // Screen1
    void gotoScreen1ScreenCoverTransitionWestImpl();

    // SubMenu1
    void gotoSubMenu1ScreenCoverTransitionWestImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
