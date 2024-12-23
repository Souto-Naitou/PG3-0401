#include "InputManager.h"

#include <Novice.h>

void InputManager::Update()
{
    /// キー入力を受け取る
    memcpy(preKeys, keys, 256);
    Novice::GetHitKeyStateAll(keys);
}

bool InputManager::IsTriggerKey(unsigned int _key) const
{
    if (!preKeys[_key] && keys[_key])
    {
        return true;
    }
    return false;
}

bool InputManager::IsPressKey(unsigned int _key) const
{
    if (keys[_key])
    {
        return true;
    }
    return false;
}
