
#include <SDL3/SDL.h>
#include <cstdlib>
#include <ctime>
#include <string>

int main(int argc, char* argv[])
{
    // Inicjalizacja SDL3
    if (!SDL_Init(SDL_INIT_VIDEO))
        return 1;

    // Tworzenie okna
    SDL_Window* window = SDL_CreateWindow(
        "Snake",
        800, 600, 0
    );

    if (!window)
    {
        SDL_Quit();
        return 1;
    }

    // Tworzenie renderera
    SDL_Renderer* renderer =
        SDL_CreateRenderer(window, nullptr);

    if (!renderer)
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Inicjalizacja generatora liczb losowych
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Gracz: x, y, szerokość, wysokość
    SDL_FRect player = { 380, 280, 40, 40 };

    // Punkt do zebrania
    SDL_FRect coin = { 150, 150, 20, 20 };

    // Zmienne gry
    bool running = true;
    int score = 0;

    float speed = 0.2f;

    SDL_Event event;

    // Główna pętla gry
    while (running)
    {
        // OBSŁUGA ZDARZEŃ
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                running = false;

            // Zamknięcie gry klawiszem Escape
            if (event.type == SDL_EVENT_KEY_DOWN)
            {
                if (event.key.key == SDLK_ESCAPE)
                    running = false;
            }
        }

        // OBSŁUGA KLAWIATURY
        const bool* keys = SDL_GetKeyboardState(nullptr);

        if (keys[SDL_SCANCODE_W])
            player.y -= speed;

        if (keys[SDL_SCANCODE_S])
            player.y += speed;

        if (keys[SDL_SCANCODE_A])
            player.x -= speed;

        if (keys[SDL_SCANCODE_D])
            player.x += speed;

        // OGRANICZENIE RUCHU DO OBSZARU OKNA
        if (player.x < 0)
            player.x = 0;

        if (player.y < 0)
            player.y = 0;

        if (player.x + player.w > 800)
            player.x = 800 - player.w;

        if (player.y + player.h > 600)
            player.y = 600 - player.h;

        // SPRAWDZANIE KOLIZJI Z PUNKTEM
        if (SDL_HasRectIntersectionFloat(&player, &coin))
        {
            score++;

            coin.x = static_cast<float>(std::rand() % 780);
            coin.y = static_cast<float>(std::rand() % 580);

            std::string title = "Snake - Wynik: "
                + std::to_string(score);

            SDL_SetWindowTitle(window, title.c_str());
        }

        // RYSOWANIE TŁA
        SDL_SetRenderDrawColor(
            renderer, 25, 25, 35, 255
        );

        SDL_RenderClear(renderer);

        // RYSOWANIE GRACZA
        SDL_SetRenderDrawColor(
            renderer, 30, 150, 255, 255
        );

        SDL_RenderFillRect(renderer, &player);

        // RYSOWANIE PUNKTU
        SDL_SetRenderDrawColor(
            renderer, 255, 220, 0, 255
        );

        SDL_RenderFillRect(renderer, &coin);

        // Wyświetlenie obrazu
        SDL_RenderPresent(renderer);
    }

    // Zwalnianie zasobów
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
