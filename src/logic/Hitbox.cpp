#include "Hitbox.h"
#include <stdexcept>
Hitbox::Hitbox(double x, double y, double w, double h) {
if (!w || !h) throw std::invalid_argument("zero sized hitbox");
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
}