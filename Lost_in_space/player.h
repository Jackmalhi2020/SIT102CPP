#ifndef LOST_IN_SPACE_PLAYER
#define LOST_IN_SPACE_PLAYER

#include "splashkit.h"
#include <vector>

using namespace std;

#define PLAYER_SPEED 1.5
#define PLAYER_ROTATE_SPEED 3
#define SCREEN_BORDER 100


enum ship_kind
{
    AQUARII,
    GLIESE,
    PEGASI
};

struct player_data
{
    sprite      player_sprite;
    int         score;
    ship_kind   kind;
    double      fuel_pct;
    double      battery_pct;
    double      health_pct;
};
player_data new_player();
void draw_player(const player_data &player_to_draw);
void update_player(player_data &player_to_update);
void handle_input(player_data &player);

#endif 