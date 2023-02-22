#include "main.h"
const float FPS = 60, UPS = 60;

int main(int argc, char *argv[])
{
    al_init_image_addon();
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
    update_timer = al_create_timer(1.0 / UPS);

    // Create the display
    // al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    display = al_create_display(1920, 1080);
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

    // Create the keyboard and mouse
    al_install_keyboard();
    al_install_mouse();
    al_hide_mouse_cursor(display);
    al_init_font_addon();
    al_init_ttf_addon();

    // Register event sources
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue , al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(redraw_timer));
    al_register_event_source(event_queue, al_get_timer_event_source(update_timer));

    // Start the timer
    al_start_timer(redraw_timer);
    al_start_timer(update_timer);

    GraphicEngine graphicEngine = GraphicEngine(al_get_display_width(display), al_get_display_height(display));
    UIEngine uiEngine = UIEngine(al_get_display_width(display), al_get_display_height(display));
    GameEngine gameEngine = GameEngine(graphicEngine, uiEngine);
    gameEngine.init();

    // GE test

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
                    if (event.timer.source == redraw_timer) redraw = true;
                    else if (event.timer.source == update_timer) gameEngine.update();
                    break;
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    running = false;
                    break;
                case ALLEGRO_EVENT_KEY_DOWN:
                    uiEngine.keyCLick(event.keyboard.keycode);
                    break;
                case ALLEGRO_EVENT_KEY_UP:
                    uiEngine.keyRealise(event.keyboard.keycode);
                    break;
                case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                    uiEngine.mouseClick(event.mouse.button);
                    break;
                case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                    printf("1");
                    uiEngine.mouseRealise(event.mouse.button);
                    break;
                case ALLEGRO_EVENT_MOUSE_AXES:
                    uiEngine.mouseMove(event.mouse.x, event.mouse.y);
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
            uiEngine.draw();
            al_flip_display();
            redraw = false;
        }
    }

    // Clean up
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}