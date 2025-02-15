#include "PlayerBullet.h"

#include <Novice.h>

void PlayerBullet::Initialize(const Vector2& _position)
{
    position_ = _position;
}

void PlayerBullet::Update()
{
    position_ += speed_;

    // 画面外に出たら死亡
    if (position_.y < -radius_ ||
        position_.y > 720 + radius_ ||
        position_.x < -radius_ ||
        position_.x > 1280 + radius_)
    {
        isDead_ = true;
    }
}

void PlayerBullet::Draw() const
{
    // プレイヤー弾を描画
    Novice::DrawEllipse(
        static_cast<int>(position_.x),
        static_cast<int>(position_.y),
        static_cast<int>(radius_),
        static_cast<int>(radius_),
        0.0f,
        0xaa44ffff,
        kFillModeSolid
    );
}
