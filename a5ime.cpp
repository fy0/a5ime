
#include "a5ime.h"
#include <stdio.h>
#include <string>
#include <windows.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_windows.h>
#include <imm.h>

bool ime_callback(ALLEGRO_DISPLAY* display, UINT msg, WPARAM wParam, LPARAM lParam, void* userdata)
{
	HWND hWnd = al_get_win_window_handle(display);

	switch (msg) {
	case WM_INPUTLANGCHANGE:
		{
			break;
		}
	case WM_IME_STARTCOMPOSITION:
		{
			break;
		}
	case WM_IME_NOTIFY:
		{
			break;
		}
	case WM_IME_COMPOSITION:
		{
			if (lParam & GCS_COMPSTR) {
				;
			} else if (lParam & GCS_RESULTSTR) {
				HIMC hIMC = ImmGetContext(hWnd);
				LONG buflen = ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, NULL, 0);

				std::wstring compstr;
				compstr.resize(buflen / 2);

				ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, &compstr[0], buflen);
				ImmReleaseContext(0, hIMC);
				for (int i=0;i<buflen/2;++i) {
					ALLEGRO_EVENT event;
					//event.type = ALLEGRO_EVENT_KEY_CHAR;
					event.type = ALLEGRO_EVENT_IME_KEY_CHAR;
					event.keyboard.unichar = compstr[i];
					event.keyboard.modifiers = 0;
					event.keyboard.keycode = 0;
					al_emit_user_event(al_get_keyboard_event_source(), &event, NULL);
				}
			}
			break;
		}
	case WM_IME_CHAR:
		{
			break;
		}
	}
	return 0;
}

bool a5ime_enable(ALLEGRO_DISPLAY* display)
{
	return al_win_add_window_callback(display, &ime_callback, NULL);
}

bool a5ime_disable(ALLEGRO_DISPLAY* display)
{
	return al_win_remove_window_callback(display, &ime_callback, NULL);
}
