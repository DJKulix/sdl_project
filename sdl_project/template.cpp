
#include <SDL3/SDL.h>

// Funkcja main - główna funkcja programu
int main(int argc, char* argv[])
{
    // Inicjalizacja biblioteki SDL3.
    // SDL_INIT_VIDEO informuje, że chcemy korzystać
    // z funkcji związanych z obrazem i oknami.
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        return 1; // Błąd inicjalizacji
    }

    // Tworzymy okno programu.
    // Argumenty:
    // 1. Tytuł okna
    // 2. Szerokość okna
    // 3. Wysokość okna
    // 4. Dodatkowe ustawienia (0 = domyślne)
    SDL_Window* window = SDL_CreateWindow(
        "Moje pierwsze okno SDL3",
        800,
        600,
        0
    );

    // Sprawdzamy, czy udało się utworzyć okno.
    if (window == nullptr)
    {
        SDL_Quit(); // Kończymy działanie SDL3
        return 1;
    }

    // Zmienna określająca, czy program ma działać.
    // true = program działa
    // false = program kończy działanie
    bool running = true;

    // SDL_Event to struktura przechowująca informacje
    // o zdarzeniach występujących w programie.
    // Mogą to być np.:
    // - naciśnięcie klawisza
    // - zwolnienie klawisza
    // - kliknięcie myszy
    // - zamknięcie okna
    SDL_Event event;

    // Główna pętla programu (Game Loop).
    // Wykonuje się tak długo, jak running == true.
    while (running)
    {
        // SDL_PollEvent pobiera kolejne oczekujące zdarzenie
        // z kolejki zdarzeń SDL.
        //
        // Zwraca true, jeśli udało się pobrać zdarzenie,
        // false, jeśli kolejka jest pusta.
        //
        // Pętla obsługuje wszystkie oczekujące zdarzenia.
        while (SDL_PollEvent(&event))
        {
            // Sprawdzamy, czy użytkownik kliknął
            // przycisk X zamykający okno.
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }

            // Sprawdzamy, czy użytkownik nacisnął klawisz.
            if (event.type == SDL_EVENT_KEY_DOWN)
            {
                // Sprawdzamy, który klawisz został naciśnięty.
                if (event.key.key == SDLK_ESCAPE)
                {
                    // Kończymy działanie pętli gry.
                    running = false;
                }

                if (event.key.key == SDLK_X)
                {
                    running = false;
                }
            }
        }
    }

    // Niszczenie okna i zwalnianie zasobów.
    SDL_DestroyWindow(window);

    // Zakończenie działania biblioteki SDL3.
    SDL_Quit();

    return 0;
}
