#ifdef _GAMEMANAGERINTERFACE_H_
#define _GAMEMANAGERINTERFACE_H_

/************************************************************************/
/* @brief This interface is used to only give essential parts to the eventhandler
/* @author Bram van Elderen
/************************************************************************/

class GameManagerInterface
{
public:
	virtual void OnEvent(int) = 0;
};

#endif