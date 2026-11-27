
# Lekcja: „Pseudo snake” w C++ i SDL3

## 1\. Cel lekcji

Celem lekcji jest przypomnienie podstaw języka C++ oraz poznanie sposobu 
tworzenia prostej gry 2D z wykorzystaniem biblioteki SDL3.

W grze sterujemy niebieskim kwadratem, zbieramy żółte punkty i zdobywamy wynik.

## 2\. Jak działa program?

Gra składa się z kilku podstawowych elementów:

- **Inicjalizacja SDL3** – przygotowanie biblioteki do pracy.
- **Tworzenie okna** – wyświetlenie okna gry.
- **Renderer** – odpowiada za rysowanie elementów na ekranie.
- **Gracz** – niebieski kwadrat, którym sterujemy.
- **Punkt** – żółty kwadrat, który należy zebrać.
- **Pętla gry** – odpowiada za ciągłe wykonywanie programu.

## 3\. Najważniejsze instrukcje i funkcje

| Instrukcja / funkcja             | Zastosowanie                          |
|----------------------------------|---------------------------------------|
| `SDL_Init()`                     | Inicjalizuje bibliotekę SDL3.         |
| `SDL_CreateWindow()`             | Tworzy okno programu.                 |
| `SDL_CreateRenderer()`           | Tworzy renderer do rysowania.         |
| `SDL_Event`                      | Przechowuje informacje o zdarzeniach. |
| `SDL_PollEvent()`                | Pobiera oczekujące zdarzenia.         |
| `SDL_GetKeyboardState()`         | Sprawdza stan klawiatury.             |
| `SDL_FRect`                      | Definiuje prostokąt i jego położenie. |
| `SDL_SetRenderDrawColor()`       | Ustawia kolor rysowania.              |
| `SDL_RenderClear()`              | Czyści ekran.                         |
| `SDL_RenderFillRect()`           | Rysuje wypełniony prostokąt.          |
| `SDL_RenderPresent()`            | Wyświetla przygotowany obraz.         |
| `SDL_HasRectIntersectionFloat()` | Sprawdza kolizję prostokątów.         |
| `SDL_DestroyWindow()`            | Usuwa okno.                           |
| `SDL_Quit()`                     | Kończy pracę biblioteki SDL3.         |

## 4\. Sterowanie graczem

Gracz porusza się za pomocą klawiszy:

| Klawisz | Kierunek        |
|---------|-----------------|
| W       | Góra            |
| S       | Dół             |
| A       | Lewo            |
| D       | Prawo           |
| ESC     | Zakończenie gry |

Za ruch odpowiada zmiana współrzędnych gracza:

```cpp
player.x += speed;
player.y += speed;
```

Wartość `speed` określa szybkość poruszania się gracza.

## 5\. Zadania do wykonania

### Zad. 1

1. Zmień kolor gracza na czerwony.
2. Zmień szybkość poruszania się gracza z 4 na 7.
3. Zwiększ rozmiar punktu do 30 × 30 pikseli.
4. Zmień kolor tła gry.
5. Zmień tytuł okna na własną nazwę gry.

### Zad. 2

1. Dodaj drugi punkt do zebrania.
2. Dodaj licznik czasu gry.
3. Sprawdź, czy gracz nie może wyjść poza obszar okna.
4. Zwiększaj szybkość gracza co 5 zebranych punktów.
5. Spraw, aby punkt pojawiał się w losowym miejscu po zebraniu.

### Zad. 3

1. Dodaj przeciwnika, którego gracz musi unikać.
2. Dodaj wykrywanie kolizji z przeciwnikiem.
3. Dodaj ekran końca gry.
4. Dodaj możliwość rozpoczęcia gry od nowa.
5. Dodaj informację o najlepszym wyniku.

## 6\. Pytania kontrolne

1. Do czego służy biblioteka SDL3?
2. Czym jest `SDL_Event`?
3. Do czego służy `SDL_PollEvent()`?
4. Czym różni się `SDL_Window` od `SDL_Renderer`?
5. Co oznaczają właściwości `x`, `y`, `w` i `h` w `SDL_FRect`?
6. Jak działa pętla `while (running)`?
7. W jaki sposób program sprawdza, czy gracz zebrał punkt?
8. Do czego służy zmienna `score`?
