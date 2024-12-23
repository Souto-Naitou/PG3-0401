#pragma once

/// <summary>
/// インプットマネージャ（シングルトン）
/// </summary>
class InputManager
{
public:
    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    InputManager(InputManager&&) = delete;
    InputManager& operator=(InputManager&&) = delete;

    /// <summary>
    /// インスタンスを取得する
    /// </summary>
    /// <returns></returns>
    static InputManager* GetInstance()
    {
        static InputManager instance;
        return &instance;
    }


public:
    /// <summary>
    /// キー入力情報更新
    /// </summary>
    void Update();


    /// <summary>
    /// キーが押された瞬間かどうかを返す
    /// </summary>
    /// <param name="_key">キー番号</param>
    /// <returns>フラグ</returns>
    bool IsTriggerKey(unsigned int _key) const;


    /// <summary>
    /// キーが離された瞬間かどうかを返す
    /// </summary>
    /// <param name="_key">キー番号</param>
    /// <returns>フラグ</returns>
    bool IsPressKey(unsigned int _key) const;


private: /// コンストラクタ / デストラクタ
    InputManager() = default;
    ~InputManager() = default;

    
private: /// メンバ変数
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };
};