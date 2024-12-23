#include <Novice.h>

#include "Scene/Manager/SceneManager.h"
#include "Scene/Title/TitleScene.h"
#include "Scene/Factory/SceneFactory.h"
#include "InputManager/InputManager.h"

const char kWindowTitle[] = "LE2B_17_ナイトウ_ソウト";

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);
    
    /// マネージャのインスタンス取得
    InputManager* inputManager = InputManager::GetInstance();
    SceneManager* sceneManager = SceneManager::GetInstance();

    // シーンファクトリのセット
    sceneManager->SetFactory(new SceneFactory());

    // 初期シーンをセット
    sceneManager->ChangeScene("TitleScene");


    /// メインループ
    while (Novice::ProcessMessage() == 0)
    {
        // フレームの開始
        Novice::BeginFrame();


        /// 更新部

        // キー入力の更新
        inputManager->Update();
        
        // シーンの更新
        sceneManager->Update();


        /// 描画部

        // シーンの描画
        sceneManager->Draw();


        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (inputManager->IsTriggerKey(DIK_ESCAPE)) break;
    }


    // シーンの終了処理
    sceneManager->Finalize();

    // ライブラリの終了
    Novice::Finalize();


    return 0;
}
