#include <SDL.h>
#include <string>
#include <cmath>
#include <math.h>
#include <vector>
#include "Vector2.h"
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

int SCREEN_WIDTH = 1320; // dimension de la pantalla
int SCREEN_HEIGHT = 680; // dimension de la pantalla
int tam = 30;
int color;
bool init();// SE inicia SDL y crea una ventana



void close();//Cierra SDL
SDL_Window* gWindow = NULL; 


SDL_Renderer* gRenderer = NULL;