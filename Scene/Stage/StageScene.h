#pragma once

#include "../../InputManager/InputManager.h"
#include "../IScene.h"
#include <Object/Player/Player.h>
#include <Object/Enemy/Enemy.h>
#include <Object/PlayerBullet/PlayerBullet.h>
#include <vector>
#include <list>
#include <memory>

/// <summary>
/// ステージシーン
/// </summary>
class StageScene : public IScene
{
public:
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;


private: /// メンバ変数
    InputManager* inputManager_ = nullptr;
    std::unique_ptr<Player> player_ = nullptr;
    std::vector<std::unique_ptr<Enemy>> enemies_ = {};
    std::list<std::unique_ptr<PlayerBullet>> playerBullets_ = {};
    const unsigned int kEnemyCount_ = 10u;


private:
    void UpdateCollision();
    void RemovePlayerBullets();
    void RemoveEnemies();


private: /// 生成関数
    void CreateEnemy();
    void CreatePlayerBullet(const Vector2& _position);
};