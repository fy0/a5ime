
#pragma once

struct ALLEGRO_DISPLAY;

#define ALLEGRO_EVENT_IME_KEY_CHAR 513

// work on windows
bool a5ime_enable(ALLEGRO_DISPLAY* display);
bool a5ime_disable(ALLEGRO_DISPLAY* display);
