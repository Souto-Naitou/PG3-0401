#include "TitleScene.h"

#include "../Manager/SceneManager.h"

#include <Novice.h>


void TitleScene::Initialize()
{
    // インプットマネージャの取得
    inputManager_ = InputManager::GetInstance();
}


void TitleScene::Update()
{
    /// スペースキーが押されたらステージシーンに遷移
    if (inputManager_->IsTriggerKey(DIK_SPACE))
    {
        SceneManager::GetInstance()->ChangeScene("StageScene");
    }
}


void TitleScene::Draw()
{
    // 背景を描画
    Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xff5555ff, kFillModeSolid);

    // 現在のシーン名を表示
    Novice::ScreenPrintf(10, 10, "[TitleScene]");

    // 次のシーンへの指示を表示
    Novice::ScreenPrintf(10, 40, "Press SPACE to StageScene");
}


void TitleScene::Finalize()
{
}
