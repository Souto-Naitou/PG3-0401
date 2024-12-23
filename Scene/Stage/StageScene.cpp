#include "StageScene.h"

#include "../Manager/SceneManager.h"

#include <Novice.h>
#include <stdlib.h>
#include <time.h>


void StageScene::Initialize()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    // マネージャのインスタンス取得
    inputManager_ = InputManager::GetInstance();

    // プレイヤーのインスタンス生成
    player_ = new Player();
    player_->Initialize(Vector2(640.0f, 640.0f));

    // メモリを確保
    enemies_.reserve(kEnemyCount_);
    playerBullets_.reserve(10);


    // 敵のインスタンス生成
    for (unsigned int i = 0; i < kEnemyCount_; i++)
    {
        this->CreateEnemy();
    }
}


void StageScene::Update()
{
    /// プレイヤーの更新
    player_->Update();


    /// プレイヤー弾の生成
    if (player_->IsShot())
    {
        this->CreatePlayerBullet(player_->GetPosition());
    }


    /// 敵の更新
    for (auto enemy : enemies_)
    {
        enemy->Update();
    }

    /// プレイヤー弾の更新
    for (auto bullet : playerBullets_)
    {
        bullet->Update();
    }
}


void StageScene::Draw()
{
    // 背景を描画
    Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x552255ff, kFillModeSolid);

    // 現在のシーン名を表示
    Novice::ScreenPrintf(10, 10, "[StageScene]");

    // プレイヤーの描画
    player_->Draw();

    // 敵の描画
    for (auto enemy : enemies_)
    {
        enemy->Draw();
    }

    // プレイヤー弾の描画
    for (auto bullet : playerBullets_)
    {
        bullet->Draw();
    }
}


void StageScene::Finalize()
{
    // プレイヤーのインスタンス破棄
    delete player_;

    // 敵のインスタンス破棄
    for (auto enemy : enemies_)
    {
        delete enemy;
    }
}

void StageScene::CreateEnemy()
{
    // インスタンスを生成
    Enemy* enemy = new Enemy();

    // 敵の半径
    float radius = enemy->GetRadius();

    // 敵の出現範囲([radius, 1280 - radius], [radius, 360 - radius])
    int rangeW = 1280 - static_cast<int>(radius * 2);
    int rangeH = 360 - static_cast<int>(radius * 2);

    // 位置をランダムに決定
    float x = static_cast<float>(rand() % rangeW + radius);
    float y = static_cast<float>(rand() % rangeH + radius);

    // 初期化
    enemy->Initialize(Vector2(x, y));

    // リストに追加
    enemies_.push_back(enemy);
}

void StageScene::CreatePlayerBullet(const Vector2& _position)
{
    // インスタンスを生成
    PlayerBullet* bullet = new PlayerBullet();

    // 初期化
    bullet->Initialize(_position);

    // リストに追加
    playerBullets_.push_back(bullet);
}
