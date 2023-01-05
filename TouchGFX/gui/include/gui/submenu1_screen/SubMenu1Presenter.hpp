#ifndef SUBMENU1PRESENTER_HPP
#define SUBMENU1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SubMenu1View;

class SubMenu1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    SubMenu1Presenter(SubMenu1View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~SubMenu1Presenter() {};

private:
    SubMenu1Presenter();

    SubMenu1View& view;
};

#endif // SUBMENU1PRESENTER_HPP
