#include <gui/setvalue_screen/SetValueView.hpp>


static int8_t BarData = 60;

SetValueView::SetValueView()
{

}

void SetValueView::setupScreen()
{
    SetValueViewBase::setupScreen();
    ProgressBarUpdate(BarData);
}

void SetValueView::tearDownScreen()
{
    SetValueViewBase::tearDownScreen();
}


void SetValueView::ProgressBarUpdate(uint8_t data)
{
	imageProgress1.setValue(data);
	textProgress1.setValue(data);

	imageProgress1.invalidate();
	textProgress1.invalidate();


}

void SetValueView::ProgressBarIncrement(void)
{
	if(BarData < 100)
		BarData++;
	ProgressBarUpdate(BarData);

}


void SetValueView::ProgressBarDecrement(void)
{
	if(BarData > 0)
		BarData--;
	ProgressBarUpdate(BarData);

}
