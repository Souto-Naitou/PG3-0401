#pragma once

#include "ISceneFactory.h"

class SceneFactory : public ISceneFactory
{
public:
    SceneFactory() = default;
    ~SceneFactory() override {};
    IScene* CreateScene(const std::string& _name) override;
};