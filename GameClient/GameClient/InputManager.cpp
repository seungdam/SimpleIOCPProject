#include "pch.h"
#include "Singleton.h"

#define WIN32_MEAN_AND_LEAN
#include <Windows.h>
#include "InputManager.h"



void CInputManager::UpdateKeyInput()
{
	for (int32 i = 0; i < 256; ++i)
	{
		if (0x0000 == GetAsyncKeyState(i)) _keyBuffer[i] = (uint8)KEY_STATE::KEY_NONE;
		else if (0x0001 == GetAsyncKeyState(i)) _keyBuffer[i] = (uint8)KEY_STATE::KEY_UP;
		else if (0x8000 == GetAsyncKeyState(i)) _keyBuffer[i] = (uint8)KEY_STATE::KEY_DOWN;
		else if (0x8001 == GetAsyncKeyState(i)) _keyBuffer[i] = (uint8)KEY_STATE::KEY_PRESSED;
	};
}

void CInputManager::SetKeyInputState(const KEY_TYPE& key, const KEY_STATE& key_state)
{
	_keyBuffer[(int32)key] = (uint8)key_state;
}

KEY_STATE CInputManager::GetKeyInputState(const KEY_TYPE& key)
{
	return (KEY_STATE)_keyBuffer[(int32)key];
}
