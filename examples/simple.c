#include "random.h"
#include "agent_manager.h"
#include "graphics.h"
#include "stdio.h"

void agtClientUpdate(struct agent *agent) 
{  
  // Create a list to hold the entities surrounding the agent
  struct list surAgts;

  // Populate the list with the entities surrounding the agent
  getSurroundingAgents(*agent, &surAgts);

  // If there are no entities surrounding the agent, move the agent in a random direction
  if (list_empty(&surAgts)) 
  {
    moveAgent(agent, getRandomDirection());
  }
  else
  {   
    // While there are still entities in the surroundingEntities list
    while (!list_empty(&surAgts))
    {
      
      struct list_elem *entityElement = list_pop_front (&surAgts);
      struct agent_base *entity = getAgentFromElement(entityElement);

      // Get the direction from the agent to the entity
      //  And try to move the agent in the direction of the entity
      enum dir directionToEntity = getDirectionFromAgentToAgent(*agent, *entity);
      bool wasMoveSuccessful = moveAgent(agent, directionToEntity);

      // If the move was not successful, move the agent in a random direction
      if (!wasMoveSuccessful) 
      {
        moveAgent(agent, getRandomDirection());
      }
      
      printf("Move was successful: %d \n", wasMoveSuccessful);
      printf("Direction to entity: %d \n", directionToEntity); 
    }
  }
  
  printf("End of agent client update. \n\n");
}

int main (int)
{
  struct masf_options opts;
  opts = agent_init (0);
  start_sim();
}