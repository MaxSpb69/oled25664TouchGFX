/*
 * F401_Buttons.hpp
 *
 *  Created on: Dec 30, 2022
 *      Author: maxsp
 */

#ifndef BUTTONS_F401_BUTTONS_HPP_
#define BUTTONS_F401_BUTTONS_HPP_


#include <platform/driver/button/ButtonController.hpp>

class F401ButtonController : public touchgfx::ButtonController
{
    virtual void init();
    virtual bool sample(uint8_t& key);

private:
    uint8_t previousState;
};


#endif /* BUTTONS_F401_BUTTONS_HPP_ */
