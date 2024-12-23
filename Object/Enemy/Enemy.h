#pragma once

#include <VecMat/Vector2.h>

class Enemy
{
public:
    void Initialize(const Vector2& _position) { position_ = _position; }
    void Update();
    void Draw() const;
    void Finalize() {};


public: /// アクセサ
    void SetPosition(const Vector2& _position) { position_ = _position; }
    Vector2 GetPosition() const { return position_; }
    float GetRadius() const { return radius_; }
    bool IsDead() const { return isDead_; }
    void SetIsDead(bool _isDead) { isDead_ = _isDead; }


private: /// メンバ変数
    Vector2 position_;
    float speed_ = 1.0f;
    float radius_ = 20.0f;
    bool isDead_ = false;
};