#include <Arduino.h>
#include "crsf.h"

enum STATE {
  STATE_INIT = 0,
  STATE_PRIMARY_ACTIVE,
  STATE_SECONDARY_ACTIVE,
  STATE_FAILSAFE
};

STATE state;

// Returns whether a packetType originating from the handset should be sent to the aircraft
bool txSideShouldUplinkSecondary(uint8_t packetType)
{
  return packetType == CRSF_FRAMETYPE_CHANNELS;
}

// Returns whether a packetType originating from the TX module should be sent to the handset
bool txSideShouldDownlinkSecondary(uint8_t packetType)
{
  return false;
}

void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop()
{
  switch (state) {
  case STATE_PRIMARY_ACTIVE:


  }
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}