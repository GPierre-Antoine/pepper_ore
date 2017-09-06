//
// Created by pa on 14/07/17.
//

#include "js_manager.h"


void pepper::dependency::js_manager::require(const js_dependency & dep)
{
    scripts.insert(dep);
}
