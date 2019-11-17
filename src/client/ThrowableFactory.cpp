#include "ThrowableFactory.h"
#include "Sprite.h"
#include "Throwable.h"
#include "Constants.h"
#include "Identifiers.h"

#define HEALTH_SPRITE "../media/sprites/health_sprite.png"
#define BOOST_SPRITE "../media/sprites/powerup.png"
#define OIL_SPRITE "../media/sprites/oil.png"
#define FLY_SPRITE "../media/sprites/throwable_sprite.png"

ThrowableFactory::ThrowableFactory(Window &window) :
window(window) { }

Throwable* ThrowableFactory::generateThrowable(EntityIdentifier type) {
    Sprite onFlySprite(window, FLY_SPRITE, 6 , 6 );
    if (type == STONE) {
        Sprite sprite(window, HEALTH_SPRITE, 2 * STONE_RADIUS, 2 * STONE_RADIUS);
        return new Throwable(std::move(sprite), std::move(onFlySprite), DEAD, 0, 0);
    }
    if (type == MUD) {
        Sprite sprite(window, HEALTH_SPRITE, 10, 10);
        return new Throwable(std::move(sprite), std::move(onFlySprite), DEAD, 0, 0);
    }
    if (type == OIL) {
        Sprite sprite(window, OIL_SPRITE, 2 * OIL_RADIUS, 2 * OIL_RADIUS);
        return new Throwable(std::move(sprite), std::move(onFlySprite), DEAD, 0, 0);
    }
    if (type == HEALTHBOOSTER) {
        Sprite sprite(window, HEALTH_SPRITE, 20, 20);
        return new Throwable(std::move(sprite), std::move(onFlySprite), DEAD, 0, 0);
    }
    if (type == SPEEDBOOSTER) {
        Sprite sprite(window, BOOST_SPRITE, 2 * BOOSTERS_RADIUS, 2 * BOOSTERS_RADIUS);
        return new Throwable(std::move(sprite), std::move(onFlySprite), DEAD, 0, 0);
    } else {
        throw std::runtime_error("Tipo de sprite inválido");
    }
}
