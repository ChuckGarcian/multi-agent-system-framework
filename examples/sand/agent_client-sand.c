#include "stdio.h"

#include "../src/util/random.h"
#include "../src/agent_manager.h"
#include "../src/graphics.h"

void agtClientUpdate(struct agent *agent) 
{  
 
  if(!moveAgent (agent, S)) moveAgent (agent, N);
 
}

int main (int)
{
  start_sim ();
}