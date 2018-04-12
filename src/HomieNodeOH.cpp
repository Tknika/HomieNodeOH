/*
 * HomieNodeOH.cpp
 *
 *  Created on: 12.04.2018
 *      Author: Aitor Iturrioz
 */

#include "HomieNodeOH.h"
#include "Homie.hpp"
#include <stddef.h>

HomieNodeOH::HomieNodeOH(const char* nodeId, const char* category, const char* itemtype) :
    HomieNode(nodeId, category)
{
    _itemtype = itemtype;
    _unit = NULL;
    _settable = false;
    _propertiesSent = false;

    advertise("itemtype");
    advertise("value");
}

HomieNodeOH::HomieNodeOH(const char* nodeId, const char* category, const char* itemtype, const char* unit) :
    HomieNode(nodeId, category)
{
    _itemtype = itemtype;
    _unit = unit;
    _settable = false;
    _propertiesSent = false;

    advertise("itemtype");
    advertise("value");
    advertise("unit");
}

HomieNodeOH::HomieNodeOH(const char* nodeId, const char* category, const char* itemtype, bool settable) :
    HomieNode(nodeId, category)
{
    _itemtype = itemtype;
    _unit = NULL;
    _settable = settable;
    _propertiesSent = false;

    advertise("itemtype");
    if (!_settable) {
        advertise("value");
    }
}

HomieNodeOH::HomieNodeOH(const char* nodeId, const char* category, const char* itemtype, const char* unit, bool settable) :
    HomieNode(nodeId, category)
{
    _itemtype = itemtype;
    _unit = unit;
    _settable = settable;
    _propertiesSent = false;

    advertise("itemtype");
    advertise("unit");
    if (!_settable) {
        advertise("value");
    }    
}

void HomieNodeOH::loop() {
    if (!_propertiesSent) {
        setProperty("itemtype").send(String(_itemtype));
        if (_unit != NULL) {
            setProperty("unit").send(String(_unit));
        }
        _propertiesSent = true;
    }
}
