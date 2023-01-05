#ifndef SETVALUEPRESENTER_HPP
#define SETVALUEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SetValueView;

class SetValuePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SetValuePresenter(SetValueView& v);

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

    virtual ~SetValuePresenter() {};

private:
    SetValuePresenter();

    SetValueView& view;
};

#endif // SETVALUEPRESENTER_HPP
