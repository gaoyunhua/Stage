
#ifndef _TRUTHSERVER_H
#define _TRUTHSERVER_H

#include "messages.h"
#include "stage_types.hh"
#include <sys/poll.h>

const int TRUTH_SERVER_PORT = 6601;
const int ENVIRONMENT_SERVER_PORT = 6602;

const int MAX_TRUTH_CONNECTIONS = 100;

// these can be modified in world_load.cc...
extern int global_truth_port;
extern int global_environment_port;

void* TruthServer( void* ); // defined in truthserver.cc
void* EnvServer( void* ); // defined in envserver.cc

typedef	struct sockaddr SA; // useful abbreviation

// packet for truth device
typedef struct
{
  int stage_id;
  StageType stage_type;

  char hostname[ HOSTNAME_SIZE ];
  
  player_id_t id;
  player_id_t parent;
  
  // stage will echo these truths if this is true
  bool echo_request; 

  //int16_t channel; // ACTS color channel (-1 = no channel)
  uint32_t x, y; // mm, mm
  uint16_t w, h; // mm, mm  
  int16_t th; // degrees
  int16_t rotdx, rotdy; // offset the body's center of rotation; mm.
  uint16_t red, green, blue;
} __attribute ((packed)) stage_truth_t;

#ifndef _XLIB_H_ // if we're not inclduing the X header

// borrow an X type for compatibility
typedef struct {
    short x, y;
} XPoint;

enum cmd_t { SAVEc = 1, LOADc, PAUSEc };

#endif // _XLIB_H

#endif // _TRUTHSERVER_H


