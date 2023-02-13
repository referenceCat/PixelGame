#include <cstdio>
#include <allegro5/allegro.h>
#include "../include/GameEngine.h"
#include "../include/GraphicEngine.h"
#include "../include/UIGraphicEngine.h"
const float FPS = 60, UPS = 60;


int main(int argc, char *argv[])
{
    GraphicEngine graphicEngine = GraphicEngine();
    UIGraphicEngine UIgraphicEngine = UIGraphicEngine();
    GameEngine gameEngine = GameEngine();
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *redraw_timer = NULL;
    ALLEGRO_TIMER *update_timer = NULL;

    bool running = true;
    bool redraw = true;

    // Initialize allegro
    if (!al_init()) {
        fprintf(stderr, "Failed to initialize allegro.\n");
        return 1;
    }

    // Initialize the timer
    redraw_timer = al_create_timer(1.0 / FPS);
    if (!redraw_timer) {
        fprintf(stderr, "Failed to create timer.\n");
        return 1;
    }

    update_timer = al_create_timer(1.0 / UPS);
    if (!update_timer) {
        fprintf(stderr, "Failed to create timer.\n");
        return 1;
    }

    // Create the display
    display = al_create_display(640, 480);
    if (!display) {
        fprintf(stderr, "Failed to create display.\n");
        return 1;
    }

    // Create the event queue
    event_queue = al_create_event_queue();
    if (!event_queue) {
        fprintf(stderr, "Failed to create event queue.");
        return 1;
    }

    // Register event sources
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(redraw_timer));
    al_register_event_source(event_queue, al_get_timer_event_source(update_timer));

    // Display a black screen
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    // Start the timer
    al_start_timer(redraw_timer);
    al_start_timer(update_timer);

    // GameEngine loop
    while (running) {
        ALLEGRO_EVENT event;
        ALLEGRO_TIMEOUT timeout;

        // Initialize timeout
        al_init_timeout(&timeout, 0.06);

        // Fetch the event (if one exists)
        bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);

        // Handle the event
        if (get_event) {
            switch (event.type) {
                case ALLEGRO_EVENT_TIMER:
                    redraw = true;
                    break;
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    running = false;
                    break;
                default:
                    fprintf(stderr, "Unsupported event received: %d\n", event.type);
                    break;
            }
        }

        // Check if we need to redraw
        if (redraw && al_is_event_queue_empty(event_queue)) {
            // Redraw
            graphicEngine.draw();
            redraw = false;
        }
    }

    // Clean up
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}