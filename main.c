#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor | (bgColor << 4));
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1; // Console coordinates start at 0
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Game_Started = 0;
char choice;
int i;

void Game_Start();

int main() {
    if (Game_Started == 0) {
        Game_Start();
    }
    return 0; // Return 0 to indicate successful completion
}

void Game_Start() {
    Game_Started = 1; // Start the game
    system("cls"); // Clear the screen

    setColor(1, 0); // Set background to blue
    gotoxy(48, 6);
    printf("Welcome To Our Game\n");

    setColor(14, 0); // Set text color to yellow
    gotoxy(52, 8);
    printf("Developed By\n");

    gotoxy(50, 10);
    printf("Mann | Taniksha\n");

    setColor(14, 0); // Set text color to yellow
    gotoxy(48, 15);
    printf("Press Any Key To Play\n");

    choice = getch(); // Wait for a key press

    if (choice == '#') {
        return; // Exit the function
    }

    setColor(14, 0); // Set text color to yellow
    gotoxy(15, 20);
    printf("Loading...");

    setColor(15, 0); // Set text color to white
    gotoxy(25, 20);

    for (i = 0; i < 53; i++) {
        printf("%c", 220); // Print a character for loading bar
    }

    setColor(12, 0); // Set text color to red
    gotoxy(25, 20);

    for (i = 0; i < 53; i++) {
        printf("%c", 220);
        Sleep(160); // Use Sleep for delay instead of delay
    }
}
