#include <Arduino.h>
#include "crsf.h"
#include "channel.h"

#define ACTIVE_LQ_THRESHOLD 85
#define FAILSAFE_LQ_THRESHOLD 70

enum STATE
{
  STATE_INIT = 0,
  STATE_PRIMARY_ACTIVE,   // we're using the primary path, secondary is active but not passing through
  STATE_SECONDARY_ACTIVE, // primary has fallen off, we're passing through on the secondary path
  STATE_FAILSAFE          // both paths are failed
};

STATE state;
CRSFChannel primary;
CRSFChannel secondary;
CRSFChannel merged;

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
}

void loop()
{
  // These will cause the channels to fetch the latest data off the UART and process a packet
  primary.loop();
  secondary.loop();
  merged.loop();

  switch (state)
  {
  case STATE_PRIMARY_ACTIVE:
    // Handle primary failsafe
    if (primary.getLQ() < FAILSAFE_LQ_THRESHOLD)
    {
      state = STATE_SECONDARY_ACTIVE;
    }
    if (primary.hasNewPacket())
    {
      merged.sendPacket(primary.getLatestPacket());
    }
  case STATE_SECONDARY_ACTIVE:
    // Return primary to service if it's alive enough
    if (primary.getLQ() > ACTIVE_LQ_THRESHOLD)
    {
      state = STATE_PRIMARY_ACTIVE;
    }
    if (secondary.hasNewPacket())
    {
      merged.sendPacket(primary.getLatestPacket());
    }
  }
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}