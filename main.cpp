#include <iostream>
#include <fstream>
#include "Triangle.h"
#include "Board.h"
#include "raylib.h"
#include <string>
using namespace std;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int SCALE = 25;
    const int screenWidth = 10 * SCALE;
    const int screenHeight = 29 * SCALE;

    Board board;
  
  string filename;
	cin >> filename;
	ifstream level(filename);

	Triangle* levelBoard[29][10];
	int parity = 1;
	string colline;

	for (int i = 0; i < 29; i++) { 
		getline(level, colline);
		for (int j = 0; j < 10; j++) {
			string col = colline.substr(0, 1);
			colline = colline.substr(2); //accounting for separator
			int color = stoi(col);
			levelBoard[i][j] = new Triangle(color, parity);
			parity *= -1;
		}
	}

	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 10; j++) {
			cout << levelBoard[i][j] << " ";
		}
		cout << endl;
	}
	Board board = Board(levelBoard);
    

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTriangle((Vector2){ 0, 0 },
                         (Vector2){ 0, 100 },
                         (Vector2){ 100, 100 }, VIOLET);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;

