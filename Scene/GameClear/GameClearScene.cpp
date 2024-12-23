#include "GameClearScene.h"

#include "../Manager/SceneManager.h"

#include <Novice.h>


void GameClearScene::Initialize()
{
    // マネージャのインスタンス取得
    inputManager_ = InputManager::GetInstance();
}


void GameClearScene::Update()
{
    /// スペースキーが押されたらタイトルシーンに遷移
    if (inputManager_->IsTriggerKey(DIK_SPACE))
    {
        SceneManager::GetInstance()->ChangeScene("TitleScene");
    }
}


void GameClearScene::Draw()
{
    // 背景を描画
    Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x5555ffff, kFillModeSolid);

    // 現在のシーン名を表示
    Novice::ScreenPrintf(10, 10, "[GameClearScene]");

    // 次のシーンへの指示を表示
    Novice::ScreenPrintf(10, 40, "Press SPACE to TitleScene");
}


void GameClearScene::Finalize()
{
}
