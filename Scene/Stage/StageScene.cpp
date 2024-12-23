#include "StageScene.h"

#include "../Manager/SceneManager.h"

#include <Novice.h>
#include <stdlib.h>
#include <time.h>


void StageScene::Initialize()
{
    // 乱数の初期化
    srand(static_cast<unsigned int>(time(nullptr)));

    // マネージャのインスタンス取得
    inputManager_ = InputManager::GetInstance();

    // プレイヤーのインスタンス生成
    player_ = std::make_unique<Player>();
    player_->Initialize(Vector2(640.0f, 640.0f));

    // メモリを確保
    enemies_.reserve(kEnemyCount_);


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
    for (auto& enemy : enemies_)
    {
        enemy->Update();
    }


    /// プレイヤー弾の更新
    for (auto& bullet : playerBullets_)
    {
        bullet->Update();
    }


    // 当たり判定の更新
    this->UpdateCollision();

    
    // 消去フラグが立っているオブジェクトの削除
    this->RemovePlayerBullets();
    this->RemoveEnemies();

    if (enemies_.size() == 0)
    {
        SceneManager::GetInstance()->ChangeScene("GameClearScene");
    }
}


void StageScene::Draw()
{
    // 背景を描画
    Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x552255ff, kFillModeSolid);

    // 現在のシーン名を表示
    Novice::ScreenPrintf(10, 10, "[StageScene]");

    /// プレイヤーの描画
    player_->Draw();

    /// 敵の描画
    for (auto& enemy : enemies_)
    {
        enemy->Draw();
    }

    /// プレイヤー弾の描画
    for (auto& bullet : playerBullets_)
    {
        bullet->Draw();
    }
}


void StageScene::Finalize()
{
    // プレイヤーの終了処理
    player_->Finalize();


    /// 敵の終了処理
    for (auto& enemy : enemies_)
    {
        enemy->Finalize();
    }


    /// プレイヤー弾の終了処理
    for (auto& bullet : playerBullets_)
    {
        bullet->Finalize();
    }
}


void StageScene::UpdateCollision()
{
    /// プレイヤー弾と敵の当たり判定
    for (auto& bullet : playerBullets_)
    {
        for (auto& enemy : enemies_)
        {
            // プレイヤー弾と敵の距離
            Vector2 distance = enemy->GetPosition() - bullet->GetPosition();

            // プレイヤー弾と敵の半径の和
            float sumRadius = enemy->GetRadius() + bullet->GetRadius();

            /// 当たり判定
            if (distance.Length() < sumRadius)
            {
                // プレイヤー弾の死亡フラグをtrueにする
                bullet->SetIsDead(true);

                // 敵の死亡フラグをtrueにする
                enemy->SetIsDead(true);
            }
        }
    }
}


void StageScene::RemovePlayerBullets()
{
    /// 死亡フラグが立っているプレイヤー弾を削除
    playerBullets_.remove_if([](const std::unique_ptr<PlayerBullet>& bullet) { return bullet->IsDead(); });
}


void StageScene::RemoveEnemies()
{
    /// 死亡フラグが立っているプレイヤー弾を削除
    auto remFirst = std::remove_if(
        enemies_.begin(),
        enemies_.end(),
        [](const std::unique_ptr<Enemy>& enm) { return enm->IsDead(); });

    // 配列から削除
    enemies_.erase(remFirst, enemies_.end());
}


void StageScene::CreateEnemy()
{
    // インスタンスを生成
    auto enemy = std::make_unique<Enemy>();

    // 敵の半径
    float radius = enemy->GetRadius();

    /// 敵の出現範囲([radius, 1280 - radius], [radius, 360 - radius])
    int rangeW = 1280 - static_cast<int>(radius * 2);
    int rangeH = 360 - static_cast<int>(radius * 2);

    /// 位置をランダムに決定
    float x = static_cast<float>(rand() % rangeW + radius);
    float y = static_cast<float>(rand() % rangeH + radius);

    // 初期化
    enemy->Initialize(Vector2(x, y));

    // リストに追加
    enemies_.emplace_back(std::move(enemy));
}


void StageScene::CreatePlayerBullet(const Vector2& _position)
{
    // インスタンスを生成
    auto bullet = std::make_unique<PlayerBullet>();

    // 初期化
    bullet->Initialize(_position);

    // リストに追加
    playerBullets_.emplace_back(std::move(bullet));
}
