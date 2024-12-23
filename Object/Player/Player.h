#pragma once

#include <VecMat/Vector2.h>
#include <InputManager/InputManager.h>

class Player
{
public:
    void Initialize(Vector2 _position);
    void Update();
    void Draw() const;
    void Finalize() {};


public: /// アクセサ
    bool IsShot() const { return isShot_; }
    Vector2 GetPosition() const { return position_; }
    float GetRadius() const { return kRadius_; }


private:
    InputManager* inputManager_ = nullptr;


private:
    Vector2 position_ = {};
    float kMoveSpeed_ = 4.0f;
    const float kRadius_ = 16.0f;
    bool isShot_ = false;
};