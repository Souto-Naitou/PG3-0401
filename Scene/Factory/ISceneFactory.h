#pragma once

#include <string>
#include "../IScene.h"

class ISceneFactory
{
public:
    ISceneFactory() = default;
    virtual ~ISceneFactory() = default;
    virtual IScene* CreateScene(const std::string& _name) = 0;
};