#include "SceneFactory.h"

#include <cassert>

#include "../Title/TitleScene.h"
#include "../Stage/StageScene.h"
#include "../GameClear/GameClearScene.h"

IScene* SceneFactory::CreateScene(const std::string& _name)
{
    if (_name == "TitleScene")
    {
        return new TitleScene();
    }
    else if (_name == "StageScene")
    {
        return new StageScene();
    }
    else if (_name == "GameClearScene")
    {
        return new GameClearScene();
    }

    assert(0 && "Invalid Scene Name");
    return nullptr;
}
