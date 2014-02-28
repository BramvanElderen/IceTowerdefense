#ifndef _ENUM_H_
#define _ENUM_H_

/************************************************************************/
/* @brief This enum is used to define certain incoming events from the game.
/* @author Bram van Elderen
/************************************************************************/
enum EnumEvent
{
	KEYPRESS_ESC,
	KEYPRESS_F,
	BUTTON_QUIT,
	BUTTON_MENU,
	BUTTON_CLEAR,
	BUTTON_TOWER,
	BUTTON_SELL,
	BUTTON_CONTROLS,
	BUTTON_STARTGAME,
	MOUSE_RIGHT_CLICK,
	MOUSE_LEFT_CLICK
};

/************************************************************************/
/* @brief This enum is used to remember certain events from the game.
/* @author Bram van Elderen
/************************************************************************/
enum EnumCurrentEvent
{
	TOWER_BUY,
	TOWER_SELL,
	EMPTY
};

/************************************************************************/
/* @brief This enum is used to define lights
/* @author Bram van Elderen
/************************************************************************/
enum EnumLight
{
	LIGHT_AMBIENT,
	LIGHT_NORMAL
};

#endif

