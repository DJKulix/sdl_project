

# Rozwiązania –

## Zadanie 1. Dodaj drugi punkt do zebrania

Tworzymy drugi prostokąt reprezentujący punkt:

cpp

```cpp
SDL_FRect coin = { 150, 150, 20, 20 };
SDL_FRect coin2 = { 500, 300, 20, 20 };
```

Rysujemy drugi punkt:

cpp

```cpp
SDL_SetRenderDrawColor(renderer, 255, 100, 0, 255);
SDL_RenderFillRect(renderer, &coin2);
```

Sprawdzamy kolizję:

cpp

```cpp
if (SDL_HasRectIntersectionFloat(&player, &coin2))
{
    score++;

    coin2.x = static_cast<float>(rand() % 780);
    coin2.y = static_cast<float>(rand() % 580);
}
```

## Zadanie 2. Dodaj licznik czasu gry

Na początku programu dodaj:

cpp

```cpp
Uint64 startTime = SDL_GetTicks();
int gameTime = 60;
```

W pętli gry obliczaj pozostały czas:

cpp

```cpp
Uint64 currentTime = SDL_GetTicks();

int elapsed = static_cast<int>(
    (currentTime - startTime) / 1000
);

int remainingTime = gameTime - elapsed;

if (remainingTime <= 0)
{
    running = false;
}
```

Aktualizuj tytuł okna:

cpp

```cpp
std::string title =
    "Wynik: " + std::to_string(score) +
    " | Czas: " + std::to_string(remainingTime);

SDL_SetWindowTitle(window, title.c_str());
```

**Wyjaśnienie:**

- `SDL_GetTicks()` zwraca liczbę milisekund od inicjalizacji SDL.
- Dzielimy różnicę czasu przez 1000, aby otrzymać sekundy.
- Po upływie 60 sekund gra się kończy.

## Zadanie 3. Zablokuj wyjście gracza poza okno

Po obsłudze ruchu gracza dodaj:

cpp

```cpp
if (player.x < 0)
    player.x = 0;

if (player.y < 0)
    player.y = 0;

if (player.x + player.w > 800)
    player.x = 800 - player.w;

if (player.y + player.h > 600)
    player.y = 600 - player.h;
```

**Wyjaśnienie:**

- Sprawdzamy pozycję gracza.
- Jeżeli wyjdzie poza lewą lub górną krawędź, ustawiamy go na granicy.
- Przy prawej i dolnej krawędzi uwzględniamy rozmiar gracza.

## Zadanie 4. Zwiększaj szybkość co 5 punktów

Dodaj zmienną:

cpp

```cpp
int lastSpeedLevel = 0;
```

Po zebraniu punktu sprawdzaj wynik:

cpp

```cpp
int speedLevel = score / 5;

if (speedLevel > lastSpeedLevel)
{
    speed += 1.0f;
    lastSpeedLevel = speedLevel;
}
```

**Wyjaśnienie:**

- `score / 5` określa poziom szybkości.
- Po zdobyciu 5, 10, 15 itd. punktów szybkość wzrasta.
- `lastSpeedLevel` zapobiega wielokrotnemu zwiększaniu szybkości w tym samym przedziale punktowym.

## Zadanie 5. Losuj nowe położenie punktu

Po zebraniu punktu wykonujemy:

cpp

```cpp
coin.x = static_cast<float>(rand() % 780);
coin.y = static_cast<float>(rand() % 580);
```

**Wyjaśnienie:**

- `rand()` generuje liczbę pseudolosową.
- Operator `%` ogranicza zakres losowania.
- Punkt otrzymuje nowe współrzędne.

Warto pamiętać, aby inicjalizację generatora wykonać tylko raz, przed pętlą gry:

cpp

```cpp
srand(static_cast<unsigned int>(time(nullptr)));
```

Nie należy losować punktu w każdym obrocie pętli gry, tylko po jego zebraniu.

## Podsumowanie poziomu 2

Uczeń powinien rozumieć:

- tworzenie wielu obiektów,
- wykrywanie kolizji,
- pomiar czasu,
- losowanie liczb,
- operatory matematyczne,
- aktualizowanie zmiennych podczas działania gry.


## Zadanie 1. Dodaj przeciwnika

Tworzymy prostokąt przeciwnika:

cpp

```cpp
SDL_FRect enemy = { 300, 100, 40, 40 };
```

Rysujemy go na ekranie:

cpp

```cpp
SDL_SetRenderDrawColor(
    renderer, 255, 50, 50, 255
);

SDL_RenderFillRect(renderer, &enemy);
```

Przeciwnik będzie czerwonym kwadratem.

## Zadanie 2. Dodaj wykrywanie kolizji z przeciwnikiem

W pętli gry dodaj:

cpp

```cpp
if (SDL_HasRectIntersectionFloat(&player, &enemy))
{
    running = false;
}
```

**Wyjaśnienie:**

Funkcja `SDL_HasRectIntersectionFloat()` sprawdza, czy dwa prostokąty nachodzą na siebie.

Jeżeli gracz dotknie przeciwnika, gra zostaje zakończona.

## Zadanie 3. Dodaj ekran końca gry

Dodaj zmienną:

cpp

```cpp
bool gameOver = false;
```

Zamiast natychmiastowego kończenia gry po kolizji wpisz:

cpp

```cpp
if (SDL_HasRectIntersectionFloat(&player, &enemy))
{
    gameOver = true;
}
```

Następnie w pętli gry dodaj obsługę ekranu końcowego:

cpp

```cpp
if (gameOver)
{
    SDL_SetRenderDrawColor(
        renderer, 100, 20, 20, 255
    );

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    continue;
}
```

**Wyjaśnienie:**

Po przegranej wyświetlamy czerwone tło zamiast normalnej planszy.

Na tym etapie nie wyświetlamy jeszcze napisu GAME OVER. Do tego można później wykorzystać SDL3\_ttf.

## Zadanie 4. Dodaj możliwość rozpoczęcia gry od nowa

W obsłudze zdarzeń dodaj:

cpp

```cpp
if (event.type == SDL_EVENT_KEY_DOWN)
{
    if (gameOver && event.key.key == SDLK_R)
    {
        // Przywracamy pozycję gracza
        player.x = 380;
        player.y = 280;

        // Przywracamy wynik
        score = 0;

        // Przywracamy szybkość
        speed = 4.0f;

        // Kończymy stan przegranej
        gameOver = false;
    }
}
```

Teraz klawisz R pozwala rozpocząć grę od nowa.

## Zadanie 5. Dodaj informację o najlepszym wyniku

Na początku programu dodaj:

cpp

```cpp
int bestScore = 0;
```

Po zdobyciu punktu sprawdzaj:

cpp

```cpp
if (score > bestScore)
{
    bestScore = score;
}
```

Możesz wyświetlać oba wyniki w tytule okna:

cpp

```cpp
std::string title =
    "Wynik: " + std::to_string(score) +
    " | Rekord: " + std::to_string(bestScore);

SDL_SetWindowTitle(window, title.c_str());
```

**Wyjaśnienie:**

- `score` przechowuje aktualny wynik.
- `bestScore` przechowuje najwyższy wynik uzyskany podczas działania programu.
- Przy nowej grze aktualny wynik zerujemy, ale rekordu nie.

