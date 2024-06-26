#include <stdbool.h>
#include <assert.h>

#include "list.h"
#include "random.h"
#include "agent.h"

/* Enum Helpers */
enum dir {N, S, W, E};

/* Manager Life Cycle */
void am_initManager (struct agent *, size_t, size_t, size_t);
void am_destroyManager (void); 

/* Agent World Perception Information */
void getSurroundingAgents(const struct agent, struct list *);
enum dir getDirectionFromAgentToAgent (const struct agent, const struct agent_base);
bool am_validPos (int posX, int posY);

/* Agent List Features Extraction */
struct agent_base *getClosestAgent (struct agent *, struct list *);
int getDistanceFromAgentToAgent  (const struct agent, const struct agent_base);

/* Agent Movement */
bool moveAgent (struct agent *, enum dir);
int moveMany (struct agent *, enum dir, int);
void randMove (struct agent *);

/* Agent creation and destruction */

/* Mistc*/ 
void printAgent(struct agent agt);
int getOpposite (enum dir);
static inline enum dir getRandomDirection(void) {return random_range (4);}
static inline struct agent_base * getAgentFromElement(struct list_elem *e) 
  {return list_entry (e, struct agent_base, elem);}