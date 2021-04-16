#include "splashkit.h"
#include "player.h"
#include "power_up.h"

void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}

int main()
{
    open_window("Jatinder Lost In Space", 800, 800);
    load_resources();
    double x, y, a, b;
    a = 500;
    b = 700;
    x = 400;
    y = 400;
    player_data player;
    player = new_player();
    power_up_data power_up;
    power_up = new_power_up(x, y);

    while (not quit_requested())
    {
        process_events();
        handle_input(player);
        update_player(player);
        update_power_up(power_up);
        clear_screen(COLOR_BLACK);
        fill_rectangle(COLOR_RED, 0, 0, 300, 90, option_to_screen());
        draw_text("LOCATION: " + point_to_string(center_point(player.player_sprite)), COLOR_WHITE, 2, 10, option_to_screen());
        draw_text("SCORE: ", COLOR_WHITE, 2, 25, option_to_screen());
        draw_text("HEALTH: ", COLOR_WHITE, 2, 40, option_to_screen());
        draw_text("BATTERY: ", COLOR_WHITE, 2, 55, option_to_screen());
        draw_bitmap("full", a, b, option_part_bmp(0, 0, 300, 0.25 * bitmap_width("full"), option_to_screen()));
        draw_bitmap("blue_bar_bubbles", a, b - 55, option_part_bmp(0, 0, 100, 0.25 * bitmap_width("blue_bar_bubbles"), option_to_screen()));
        draw_bitmap("purple_bar", a, b - 110, option_part_bmp(0, 0, 150, 0.25 * bitmap_width("purple_bar"), option_to_screen()));
        fill_rectangle(COLOR_BLACK, 50, 660, 100, 100, option_to_screen());
        fill_rectangle(COLOR_WHITE, 400, 400, 10, 10);
        fill_circle(COLOR_YELLOW, 250, 150, 50);
        draw_player(player);
        draw_power_up(power_up);

        refresh_screen(60);
    }

    return 0;
}