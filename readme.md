## About

CRSFMUX is a open source solution for splitting a single CRSF feed into two simultaneous control links/CRSF links, Then returning it back to one CRSF feed for using in a flight controller or CRSF input device.

![Banner](/images/CRSFMUX.svg)


Side A: Take in a CRSF feed from a CRSF device (i.e. a Handset) and output two simultaneous CRSF feeds (primary & secondary). Primary passes back telemetry and EdgeTX sync frames

Side B: Take in two CRSF feeds from the receivers, select the primary/secondary, then send it out as a single CRSF feed to the CRSF device (i.e. a Flight Controller)

The idea is to put a 433MHz/2.4GHz combo, or a Crossfire/ELRS combo, or a DragonLink/Crossfire, Any device that can input/output CRSF, and be able to hot swap between links if the primary link gets unstable or drops below a certain LQ threshold.