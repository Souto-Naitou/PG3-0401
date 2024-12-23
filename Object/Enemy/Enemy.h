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


private: /// メンバ変数
    Vector2 position_;
    float speed_ = 3.0f;
    float radius_ = 20.0f;
};