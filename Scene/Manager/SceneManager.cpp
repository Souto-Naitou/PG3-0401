#include "SceneManager.h"

void SceneManager::ChangeScene(std::string _name)
{
    /// 現在のシーンの終了処理
    if (pCurrentScene_ != nullptr)
    {
        pCurrentScene_->Finalize();
        delete pCurrentScene_;
    }

    /// 新しいシーンの生成と初期化
    pCurrentScene_ = pFactory_->CreateScene(_name);
    pCurrentScene_->Initialize();
}

void SceneManager::Update()
{
    /// シーンの更新
    if (pCurrentScene_)
    {
        pCurrentScene_->Update();
    }
}

void SceneManager::Draw()
{
    /// シーンの描画
    if (pCurrentScene_)
    {
        pCurrentScene_->Draw();
    }
}

void SceneManager::Finalize()
{
    /// シーンの終了処理
    if (pCurrentScene_)
    {
        pCurrentScene_->Finalize();
        delete pCurrentScene_;
    }
}
