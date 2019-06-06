#include "CustomTrainingUnlimitedTimePlugin.h"

BAKKESMOD_PLUGIN(CustomTrainingUnlimitedTimePlugin, "Custom Training Unlimited Time", "0.1.0", PLUGINTYPE_CUSTOM_TRAINING)

void CustomTrainingUnlimitedTimePlugin::onLoad()
{
    unlimited_time = std::make_shared<bool>(false);

    auto update = std::bind(&CustomTrainingUnlimitedTimePlugin::UpdateServerUnlimitedTime, this);
    auto cvar = cvarManager->registerCvar(
        "sv_training_unlimited_time",
        std::to_string(*unlimited_time),
        "Toggles unlimited time in custom training"
    );

    cvar.bindTo(unlimited_time);
    cvar.addOnValueChanged(update);

    gameWrapper->HookEventPost("Function TAGame.GameEvent_TrainingEditor_TA.StartPlayTest", update);
}

void CustomTrainingUnlimitedTimePlugin::UpdateServerUnlimitedTime()
{
        if (!this->gameWrapper->IsInCustomTraining())
        {
            return;
        }
        this->gameWrapper->GetGameEventAsServer().SetbUnlimitedTime(*this->unlimited_time);
}

void CustomTrainingUnlimitedTimePlugin::onUnload()
{
}