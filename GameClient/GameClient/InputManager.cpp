#include "pch.h"
#include "Singleton.h"

#include <WinUser.h>
#include "InputManager.h"



static void CInputManager::UpdateKeyInput()
{
	for(int32 i = 0; i < 256; ++i) 
}

void CInputManager::SetKeyInputState(const KEY_STATE& key_state)
{
}

KEY_STATE CInputManager::GetKeyInputState(const KEY_TYPE& key)
{
	return KEY_STATE();
}
