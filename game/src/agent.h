/* Agent Object */
struct agent
{
  int posX;
  int posY;

  int perceptual_radius;
  int action_radius;
  void (*updateAgent)(struct agent *);
  /* C function pointers cheatsheet */
};




//evoid updateAgent (static agent);