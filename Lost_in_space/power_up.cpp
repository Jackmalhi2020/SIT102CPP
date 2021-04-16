#include "splashkit.h"
#include "power_up.h"

bitmap power_up_bitmap(power_up_kind kind)
{
    switch (kind)
    {
    case SHIELD:
        return bitmap_named("power");
    case POTION:
        return bitmap_named("potion");
    case BATTERY:
        return bitmap_named("shield");
    case CASH:
        return bitmap_named("cash");
    case TIME:
        return bitmap_named("time");
    case FUEL:
    default:
        return bitmap_named("fuel");
    }
}

power_up_data new_power_up(double x, double y)
{
    power_up_data result;
    bitmap default_power_bitmap = power_up_bitmap(static_cast<power_up_kind>(rnd(5)));
    result.power_up_sprite = create_sprite(default_power_bitmap);
    sprite_set_x(result.power_up_sprite, x); // set the location x & y
    sprite_set_y(result.power_up_sprite, y);
    sprite_set_dx(result.power_up_sprite, rnd() * 4 - 2); // set the horizontal speed
    sprite_set_dy(result.power_up_sprite, rnd() * 4 - 2); // set the vertical speed
    sprite_add_layer(result.power_up_sprite, power_up_bitmap(FUEL), "fuel");
    sprite_add_layer(result.power_up_sprite, power_up_bitmap(CASH), "cash");
    sprite_add_layer(result.power_up_sprite, power_up_bitmap(TIME), "time");
    sprite_add_layer(result.power_up_sprite, power_up_bitmap(BATTERY), "battery");
    sprite_hide_layer(result.power_up_sprite, 1);
    sprite_hide_layer(result.power_up_sprite, 2);
    sprite_hide_layer(result.power_up_sprite, 3);
    sprite_hide_layer(result.power_up_sprite, 4);
    sprite_hide_layer(result.power_up_sprite, 5);
    result.kind = SHIELD;
    return result;
}
void draw_power_up(const power_up_data &power_up_to_draw)
{
    double x, y;
    x = rnd();
    y = rnd();
    draw_sprite(power_up_to_draw.power_up_sprite, x, y);
}
void update_power_up(power_up_data &power_up_to_update)
{
    update_sprite(power_up_to_update.power_up_sprite);
}
