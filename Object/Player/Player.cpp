#include "Player.h"

#include <Novice.h>

void Player::Initialize(Vector2 _position)
{
    // インスタンス取得
    inputManager_ = InputManager::GetInstance();

    // 座標の初期化
    position_ = _position;
}

void Player::Update()
{
    // 発射フラグの初期化
    isShot_ = false;

    // 入力情報の更新
    if (inputManager_->IsPressKey(DIK_W))
    {
        position_.y -= kMoveSpeed_;
    }
    if (inputManager_->IsPressKey(DIK_S))
    {
        position_.y += kMoveSpeed_;
    }
    if (inputManager_->IsPressKey(DIK_A))
    {
        position_.x -= kMoveSpeed_;
    }
    if (inputManager_->IsPressKey(DIK_D))
    {
        position_.x += kMoveSpeed_;
    }
    if (inputManager_->IsTriggerKey(DIK_SPACE))
    {
        isShot_ = true;
    }
}

void Player::Draw() const
{
    /// プレイヤーを描画
    Novice::DrawEllipse(
        static_cast<int>(position_.x),
        static_cast<int>(position_.y),
        static_cast<int>(kRadius_),
        static_cast<int>(kRadius_),
        0.0f,
        0x00ff00ff,
        kFillModeSolid
    );
}
