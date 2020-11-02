// Copyright 2020 Valentin Vanelslande
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common_types.h"

#ifdef _WIN32
#define VVCTRE_PLUGIN_EXPORT __declspec(dllexport)
#else
#define VVCTRE_PLUGIN_EXPORT
#endif

static const char* required_function_names[] = {
    "vvctre_settings_set_use_custom_cpu_ticks",
    "vvctre_settings_set_custom_cpu_ticks",
    "vvctre_settings_set_custom_textures",
    "vvctre_settings_set_resolution",
    "vvctre_settings_set_layout",
    "vvctre_settings_set_nickname",
};

typedef void (*vvctre_settings_set_use_custom_cpu_ticks_t)(bool value);
static vvctre_settings_set_use_custom_cpu_ticks_t vvctre_settings_set_use_custom_cpu_ticks;
typedef void (*vvctre_settings_set_custom_cpu_ticks_t)(u64 value);
static vvctre_settings_set_custom_cpu_ticks_t vvctre_settings_set_custom_cpu_ticks;
typedef void (*vvctre_settings_set_custom_textures_t)(bool value);
static vvctre_settings_set_custom_textures_t vvctre_settings_set_custom_textures;
typedef void (*vvctre_settings_set_resolution_t)(u16 value);
static vvctre_settings_set_resolution_t vvctre_settings_set_resolution;
typedef void (*vvctre_settings_set_layout_t)(int value);
static vvctre_settings_set_layout_t vvctre_settings_set_layout;
typedef void (*vvctre_settings_set_nickname_t)(const char* value);
static vvctre_settings_set_nickname_t vvctre_settings_set_nickname;

VVCTRE_PLUGIN_EXPORT int GetRequiredFunctionCount() {
    return 6;
}

VVCTRE_PLUGIN_EXPORT const char** GetRequiredFunctionNames() {
    return required_function_names;
}
    
VVCTRE_PLUGIN_EXPORT void PluginLoaded(void* core, void* plugin_manager, void* required_functions[]) {
    vvctre_settings_set_use_custom_cpu_ticks = (vvctre_settings_set_use_custom_cpu_ticks_t)required_functions[0];
    vvctre_settings_set_custom_cpu_ticks = (vvctre_settings_set_custom_cpu_ticks_t)required_functions[1];
    vvctre_settings_set_custom_textures = (vvctre_settings_set_custom_textures_t)required_functions[2];
    vvctre_settings_set_resolution = (vvctre_settings_set_resolution_t)required_functions[3];
    vvctre_settings_set_layout = (vvctre_settings_set_layout_t)required_functions[4];
    vvctre_settings_set_nickname = (vvctre_settings_set_nickname_t)required_functions[5];
}


VVCTRE_PLUGIN_EXPORT void InitialSettingsOpening() {
    vvctre_settings_set_use_custom_cpu_ticks(true);
    vvctre_settings_set_custom_cpu_ticks(77);
    vvctre_settings_set_custom_textures(true);
    vvctre_settings_set_resolution(4);
    vvctre_settings_set_layout(2);
    vvctre_settings_set_nickname("Outssiss");
}
