#include "../src/util/random.h"
#include "../src/agent_manager.h"
#include "stdio.h"
#include "config.h"

void agtClientUpdate(struct agent *agent)
{
  // Create a list to hold the entities surrounding the agent
  struct list surAgts;

  // Populate the list with the entities surrounding the agent
  getSurroundingAgents(*agent, &surAgts);

  // If there are no entities surrounding the agent, move the agent in a random direction

  // While there are still entities in the surroundingEntities list
  while (!list_empty(&surAgts))
  {

    struct list_elem *entityElement = list_pop_front(&surAgts);
    struct agent_base *entity = getAgentFromElement(entityElement);

    //  Get the direction from the agent to the entity
    //  And try to move the agent in the direction of the entity
    if (entity->ID < agent->my_base.ID)
    {
      bool wasMoveSuccessful;
      enum dir directionToEntity = getDirectionFromAgentToAgent(*agent, *entity);
      if (getDistanceFromAgentToAgent (*agent, *entity) < 6)
        wasMoveSuccessful = moveAgent(agent, -1 * directionToEntity);
      else 
        wasMoveSuccessful = moveAgent (agent, directionToEntity);
      
      if (wasMoveSuccessful)
        return;
    }
  }

  randMove (agent); 
}


int main (void)
{
  start_sim ();
}
