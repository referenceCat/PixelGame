#include "FunctionalKey.h"

FunctionalKey FunctionalKey::MOVE_UP{"Move up", ALLEGRO_KEY_W};
FunctionalKey FunctionalKey::MOVE_DOWN{"Move down", ALLEGRO_KEY_S};
FunctionalKey FunctionalKey::MOVE_LEFT{"Move left", ALLEGRO_KEY_A};
FunctionalKey FunctionalKey::MOVE_RIGHT{"Move right", ALLEGRO_KEY_D};
FunctionalKey FunctionalKey::ZOOM_IN{"Zoom in", ALLEGRO_KEY_EQUALS};
FunctionalKey FunctionalKey::ZOOM_OUT{"Zoom out", ALLEGRO_KEY_MINUS};

FunctionalKey FunctionalKey::allKeys[6] = {FunctionalKey::MOVE_UP,
                                            FunctionalKey::MOVE_DOWN,
                                            FunctionalKey::MOVE_LEFT,
                                            FunctionalKey::MOVE_RIGHT,
                                            FunctionalKey::ZOOM_IN,
                                            FunctionalKey::ZOOM_OUT};