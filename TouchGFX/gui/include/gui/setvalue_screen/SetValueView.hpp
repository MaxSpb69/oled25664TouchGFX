#ifndef SETVALUEVIEW_HPP
#define SETVALUEVIEW_HPP

#include <gui_generated/setvalue_screen/SetValueViewBase.hpp>
#include <gui/setvalue_screen/SetValuePresenter.hpp>

class SetValueView : public SetValueViewBase
{
public:
    SetValueView();
    virtual ~SetValueView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void ProgressBarUpdate(uint8_t data);
    virtual void ProgressBarIncrement();
    virtual void ProgressBarDecrement();
protected:
};

#endif // SETVALUEVIEW_HPP
