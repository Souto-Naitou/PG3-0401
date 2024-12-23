#include "Enemy.h"

#include <Novice.h>

void Enemy::Update()
{
    /// 画面外に出たら反転
    if (position_.x >= 1280.0f - radius_ || position_.x <= 0.0 + radius_)
    {
        speed_ *= -1.0f;
    }

    // 位置を更新
    position_.x += speed_;
}

void Enemy::Draw() const
{
    // 敵を描画
    Novice::DrawEllipse(
        static_cast<int>(position_.x),
        static_cast<int>(position_.y),
        static_cast<int>(radius_),
        static_cast<int>(radius_),
        0.0f,
        0xff0000ff,
        kFillModeSolid
    );
}
