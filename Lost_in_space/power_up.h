#ifndef POWER_UP
#define POWER_UP
#define SCREEN_BORDER 100
#include <string>
using std::string;
#include <vector>


enum power_up_kind
{
    FUEL,
    BATTERY,
    POTION,
    SHIELD,
    CASH,
    TIME
};

struct power_up_data
{
    power_up_kind      kind;
    sprite             power_up_sprite;
};

power_up_data new_power_up(double x, double y);
bitmap power_up_bitmap(power_up_kind kind);
void draw_power_up(const power_up_data &power_up_to_draw);
void update_power_up(power_up_data &power_up_to_update);
#endif