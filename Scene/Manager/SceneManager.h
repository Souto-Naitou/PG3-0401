#pragma once

#include "../IScene.h"
#include "../Factory/ISceneFactory.h"
#include <type_traits>

/// <summary>
/// シーンマネージャ（シングルトン）
/// </summary>
class SceneManager
{
public:
    SceneManager(SceneManager const&) = delete;
    SceneManager& operator=(SceneManager const&) = delete;
    SceneManager(SceneManager&&) = delete;
    SceneManager& operator=(SceneManager&&) = delete;

    /// <summary>
    /// インスタンスを取得する
    /// </summary>
    /// <returns></returns>
    static SceneManager* GetInstance()
    {
        static SceneManager instance;
        return &instance;
    }
    

public:
    /// <summary>
    /// ファクトリをセットする
    /// </summary>
    /// <param name="_factory">ファクトリのインスタンス</param>
    void SetFactory(ISceneFactory* _factory)
    {
        pFactory_ = _factory;
    }


    /// <summary>
    /// シーンを変更する
    /// </summary>
    /// <param name="_name">シーン名</param>
    void ChangeScene(std::string _name);


    void Update();
    void Draw();
    void Finalize();


private: /// コンストラクタ / デストラクタ
    SceneManager() = default;
    ~SceneManager() = default;


private: /// メンバ変数
    IScene* pCurrentScene_ = nullptr;
    ISceneFactory* pFactory_ = nullptr;
};