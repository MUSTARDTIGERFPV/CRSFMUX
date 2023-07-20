#pragma once
#include <stdio.h>
#include <stdint.h>
#include "crsf.h"

struct CRSFRawPacket {
    uint8_t *buf;
    size_t len;
};

class CRSFChannel {
public:
    uint8_t getLQ();
    bool hasNewPacket();
    void loop();
    CRSFRawPacket getLatestPacket();
    void sendPacket(CRSFRawPacket packet);
private:
    uint32_t packetIndex = 0;
    uint8_t packet[CRSF_FRAME_SIZE_MAX] = { 0 };
};