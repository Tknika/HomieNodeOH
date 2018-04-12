/*
 * HomieNodeOH.h
 *
 *  Created on: 12.04.2018
 *      Author: Aitor Iturrioz
 */

#ifndef SRC_HOMIENODEOH_H_
#define SRC_HOMIENODEOH_H_

#include <HomieNode.hpp>

class HomieNodeOH: public HomieNode {
public:
    HomieNodeOH(const char* nodeId, const char* category, const char* itemtype);
    HomieNodeOH(const char* nodeId, const char* category, const char* itemtype, const char* unit);
    HomieNodeOH(const char* nodeId, const char* category, const char* itemtype, bool settable);
    HomieNodeOH(const char* nodeId, const char* category, const char* itemtype, const char* unit, bool settable);
    virtual void loop() override;

private:
    const char* _itemtype;
    const char* _unit;
    bool _settable;
    bool _propertiesSent;
};

#endif

