#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"

class CustomTrainingUnlimitedTimePlugin : public BakkesMod::Plugin::BakkesModPlugin
{
private:
    std::shared_ptr<bool> unlimited_time;
    void UpdateServerUnlimitedTime();

public:
    virtual void onLoad();
    virtual void onUnload();
};