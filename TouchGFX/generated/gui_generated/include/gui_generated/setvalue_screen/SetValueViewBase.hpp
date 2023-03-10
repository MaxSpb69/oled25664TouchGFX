/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SETVALUEVIEWBASE_HPP
#define SETVALUEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/setvalue_screen/SetValuePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TiledImage.hpp>
#include <touchgfx/containers/progress_indicators/ImageProgress.hpp>
#include <touchgfx/containers/progress_indicators/TextProgress.hpp>

class SetValueViewBase : public touchgfx::View<SetValuePresenter>
{
public:
    SetValueViewBase();
    virtual ~SetValueViewBase();
    virtual void setupScreen();
    virtual void handleKeyEvent(uint8_t key);

    /*
     * Virtual Action Handlers
     */
    virtual void ProgressBarIncrement()
    {
        // Override and implement this function in SetValue
    }
    virtual void ProgressBarDecrement()
    {
        // Override and implement this function in SetValue
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::TiledImage tiledImage1;
    touchgfx::ImageProgress imageProgress1;
    touchgfx::TextProgress textProgress1;

private:

};

#endif // SETVALUEVIEWBASE_HPP
