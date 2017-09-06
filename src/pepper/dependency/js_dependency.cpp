//
// Created by pa on 14/07/17.
//

#include "js_dependency.h"

std::string pepper::dependency::js_dependency::get() const
{
    return lib;
}

bool pepper::dependency::js_dependency::operator==(const pepper::dependency::js_dependency &rhm)const noexcept {
    return rhm.get() == this->get();
}

void pepper::dependency::js_dependency::ask_dependency(pepper::dependency::js_manager &manager) const {
    for (auto rlib : this->requirements)
        manager.require(rlib);
}

pepper::dependency::js_dependency::js_dependency(const std::string &lib, const std::initializer_list<pepper::dependency::js_dependency> &requirements):lib (lib),requirements(requirements)
{

}