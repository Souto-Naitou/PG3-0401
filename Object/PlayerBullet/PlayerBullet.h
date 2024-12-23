#pragma once

#include <VecMat/Vector2.h>


/// <summary>
/// プレイヤー弾
/// </summary>
class PlayerBullet
{
public:
    void Initialize(const Vector2& _position);
    void Update();
    void Draw() const;
    void Finalize() {};


public: /// アクセサ
    bool IsDead() const { return isDead_; }
    Vector2 GetPosition() const { return position_; }
    float GetRadius() const { return radius_; }
    void SetIsDead(bool _isDead) { isDead_ = _isDead; }


private:
    Vector2 position_;
    Vector2 speed_ = { 0.0f, -5.0f };
    float radius_ = 5.0f;
    bool isDead_ = false;
};