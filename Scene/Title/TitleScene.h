#pragma once

#include "../../InputManager/InputManager.h"
#include "../IScene.h"

/// <summary>
/// タイトルシーン
/// </summary>
class TitleScene : public IScene
{
public:
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;


private: /// メンバ変数
    InputManager* inputManager_ = nullptr;
};