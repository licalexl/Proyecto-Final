#include "main.h"
#include <string>
#include <cmath>
#include <math.h>
#include <vector>
#include "Vector2.h"
#include <SDL_image.h>
using namespace std;
int mouseX, mouseY;
int previousMouseX, previousMouseY;
bool leftButton;
bool rightButton;
bool running;

void clear()
{
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	SDL_RenderClear(gRenderer);
}
void setButtonState(Uint8 button, bool state)
{
	switch (button)
	{
	case SDL_BUTTON_LEFT:
		leftButton = state;
		break;
	case SDL_BUTTON_RIGHT:
		rightButton = state;
		break;
	}
	}
	void Pluma()
{
	if(running = true){
	previousMouseX = mouseX, previousMouseY = mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	if(leftButton)
	{
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderDrawLine(gRenderer, previousMouseX, previousMouseY, mouseX, mouseY);
		//SDL_RenderDrawPoint(gRenderer, mouseX, mouseY);
	}
	else if (rightButton)
	{
		SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
		//SDL_RenderDrawPoint(gRenderer, mouseX, mouseY);
		SDL_RenderDrawLine(gRenderer, previousMouseX, previousMouseY, mouseX, mouseY);
	}
	SDL_RenderPresent(gRenderer);
	}
}
void (handleEvent(SDL_Event& event))
{
	switch (event.type)
	{
	case SDL_QUIT:
		running = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		setButtonState(event.button.button, true);
		Pluma();
		break;
	case SDL_MOUSEBUTTONUP:
		setButtonState(event.button.button, false);
		Pluma();
		break;
	case SDL_MOUSEMOTION:
		Pluma();
		break; 
	}
}
void loop()
{
	while (running) 
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			handleEvent(event);

		}

	}
}



void Bresenham(int xa, int ya, int xb, int yb)
{

    int signx;
    int signy;
    int x;
    int y;
    int i;
    int Punto;

    x = xa;
    y = ya;

    int dx = xb - xa;
    int dy = yb - ya;

    if (dx >= 0) {
        signx = +1;
    }
    else {
        signx = -1;
    }
    if (dy >= 0) {
        signy = 1;
    }
    else {
        signy = -1;
    }
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
    if (x == xb)
    {
        SDL_RenderDrawLine(gRenderer, x, y, xb, yb);
    }
    if (abs(dy) <= abs(dx)) {

        Punto = 2 * dy * signy - dx * signx;
        for (i = 0; i <= dx * signx; i++)
        {
            SDL_RenderDrawPoint(gRenderer, x, y);
            if (Punto < 0) {

                x = x + signx;
                y = y;
                Punto = Punto + signy * 2 * dy;
            }
            else {

                x = x + signx;
                y = y + signy;
                Punto = Punto + 2 * dy * signy - 2 * dx * signx;
            }
        }
    }
    else if (abs(dy) > abs(dx)) {

        Punto = signx * 2 * dx - signy * dy;
        i = 0;

        for (i = 0; i <= dy * signy; i++)
        {
            SDL_RenderDrawPoint(gRenderer, x, y);
            if (Punto < 0)
            {
                x = x;
                y = y + signy;
                Punto = Punto + signx * 2 * dx;
            }
            else
            {
                x = x + signx;
                y = y + signy;
                Punto = Punto + signx * 2 * dx - signy * 2 * dy;
            }
        }
    }

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}


void DibujarLineaB(Vector2 v1, Vector2 v2)
{
    Bresenham(v1.getX(), v1.getY(), v2.getX(), v2.getY());
}

void VectorCuadrado(const std::vector<Vector2>& vertex)
{

    for (auto it = vertex.begin(); it != vertex.end(); it++)
    {
        if (it + 1 != vertex.end())
        {
            DibujarLineaB(*it, *(it + 1));
        }
        else if (it + 1 == vertex.end())
        {
            DibujarLineaB(*it, vertex.front());
        }
    }
}

void Circulo(int r, int xc, int yc)
{
    
    int Punto, x, y;
    Punto = 1 - r;
    x = 0;
    y = r;
    if (color == 1)
    {
       SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
    }
    else if (color == 2)
    {
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x4f, 0x3F, 0x5F);
    }
    else if (color == 3)
    {
        SDL_SetRenderDrawColor(gRenderer, 12, 14, 128, 0);
    }
    else if (color == 4)
    {
        SDL_SetRenderDrawColor(gRenderer, 128, 12, 89, 0);
    }

    for (;x <= y;)
    {
        if (Punto <= 0)
        {
            x = x + 1;
            y = y;
            Punto = Punto + (4 * x) + 6;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            Punto = Punto + 4 * (x - y) + 10;
        }

        SDL_RenderDrawPoint(gRenderer, x + xc, y + yc);
        SDL_RenderDrawPoint(gRenderer, -x + xc, y + yc);
        SDL_RenderDrawPoint(gRenderer, -x + xc, -y + yc);
        SDL_RenderDrawPoint(gRenderer, x + xc, -y + yc);
        SDL_RenderDrawPoint(gRenderer, y + xc, x + yc);
        SDL_RenderDrawPoint(gRenderer, -y + xc, x + yc);
        SDL_RenderDrawPoint(gRenderer, -y + xc, -x + yc);
        SDL_RenderDrawPoint(gRenderer, y + xc, -x + yc);
        
        
    }
    
}


float DibujarLinea(float Xa, float Ya, float Xb, float Yb)
{
    float Memoria, dx, dy, Yinc, Xinc, X, Y;
    int i = 0;
    
    dx = Xb - Xa;
    dy = Yb - Ya;

    if (abs(dy) < abs(dx))
    {
        Memoria = abs(dx);
    }
    else if (abs(dy) >= abs(dx))
    {
        Memoria = abs(dy);
    }

    Xinc = dx / Memoria;
    Yinc = dy / Memoria;
    X = Xa;
    Y = Ya;


    for (int i = 0; i <= Memoria; i++)
    {
        SDL_RenderDrawPoint(gRenderer, X, Y);
        X = X + Xinc;
        Y = Y + Yinc;
    }

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);



    return  0;
}


bool init()
{
   
    bool success = true;


   
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("", SDL_GetError());
        success = false;
    }
    else
    {
        
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("");
        }

  
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
         
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
               
                SDL_SetRenderDrawColor(gRenderer, 0xDD, 0xFF, 0xFF, 0xFF);


            }


		
        }
    }

    return success;
}

void close()
{
   
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;


    SDL_Quit();
}

void SetScreen()
{
    if (SCREEN_WIDTH == 0 || SCREEN_HEIGHT == 0)
    {
        SCREEN_WIDTH = 720;
        SCREEN_HEIGHT = 480;
    }
    if (tam == 0)
    {
        tam = 32;
    }
}

void DrawPlain()
{
    SDL_SetRenderDrawColor(gRenderer, 0x2F, 0xdd, 0xfF, 0xb2);

   
    SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    for (int i = SCREEN_HEIGHT / 2; i < SCREEN_HEIGHT;)
    {
        i += tam;
        SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT - i);
        SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
    }

    for (int i = SCREEN_WIDTH / 2; i < SCREEN_WIDTH;)
    {
        i += tam;
        SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - i, SCREEN_HEIGHT / 2);
        SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT / 2);
    }

    SDL_SetRenderDrawColor(gRenderer, 0x2F, 0xdd, 0xfF, 0xb2);
    for (int i = (SCREEN_WIDTH / 2) + tam; i < SCREEN_WIDTH; i += tam)
    {
        for (int j = (SCREEN_HEIGHT / 2) + tam; j < SCREEN_HEIGHT; j += tam)
        {
            SDL_RenderDrawPoint(gRenderer, i, j);
            SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - i, j);
            SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - i, SCREEN_HEIGHT - j);
            SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT - j);
        }
    }


}

void BezierCurve(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4)
{
    float x = 0;
    float y = 0;
    Vector2 Vect = Vector2(x, y);

    
	
	
	if (color == 1)
    {
        SDL_SetRenderDrawColor
		(gRenderer, 0x00, 0x00, 0x00, 0x00);
    }
    
	
	
	
	else if (color == 2)
    {
        SDL_SetRenderDrawColor
		(gRenderer, 0xFF, 0x4f, 0x3F, 0x5F);
    }
    
	
	else if (color == 3)
    {
        SDL_SetRenderDrawColor
		(gRenderer, 12, 14, 128, 0);
    }
    
	else if (color == 4)
    {
        SDL_SetRenderDrawColor
		(gRenderer, 128, 12, 89, 0);
    }
    for (float t = 0; t <= 1; t += .001)
    {
        x = pow(1 - t, 3) * v1.getX() + 3 * t * pow(1 - t, 2) * v2.getX() + 3 * 
			pow(t, 2) * (1 - t) * v3.getX() + pow(t, 3) * v4.getX();
        y = pow(1 - t, 3) * v1.getY() + 3 * t * pow(1 - t, 2) * v2.getY() + 3 * 
			pow(t, 2) * (1 - t) * v3.getY() + pow(t, 3) * v4.getY();
        SDL_RenderDrawPoint
		(gRenderer, x, y);
    }
    SDL_SetRenderDrawColor
	(gRenderer, 0x44, 0x44, 0x44, 0xFF);

}

int main(int argc, char* args[])
{
	
	if (!init()) return 0;
	running = true;
	leftButton = false;
	rightButton = false;
	clear();
	loop();
	SDL_Texture* texture;
	SDL_Surface* surface;
	/*surface = IMG_Load("123.jpg");*/


    int x1 = 0; int y1 = 0; int x2 = 0; int y2 = 0; bool drawing = false;

    struct Line
    {
		int x1, y1, x2, y2;
    };
    struct Circles
    {
		int x1, y1, x2, y2;
    };
    struct Curves
    {
		int x1, y1, x2, y2;
    };
   
   list<Curves>curves;list<Circles>circles; list<Line>lines;
   SetScreen();
   if (!init())
   {
       printf("Failed to initialize!\n");
   }
  else {
 bool quit = false;bool boton1 = false;bool boton2 = false;bool boton3 = false;bool boton4 = false;
SDL_Event PrimerBoton;
  while (!quit)
  {
  while (SDL_PollEvent(&PrimerBoton) != 0)
  {switch (PrimerBoton.type)
  {case SDL_MOUSEBUTTONDOWN:
  switch (PrimerBoton.button.button)
  {case SDL_BUTTON_LEFT:
  x1 = PrimerBoton.button.x;
  y1 = PrimerBoton.button.y;
  x2 = PrimerBoton.button.x;
  y2 = PrimerBoton.button.y;
  drawing = true;
  break;}
  break; 
  case SDL_MOUSEBUTTONUP:
  switch (PrimerBoton.button.button)
     {
     case SDL_BUTTON_LEFT: drawing = false;
     Line line = { x1, y1, x2, y2 };Circles circle = { x1,y1,x2,y2 };Curves curve = {x1,y1,x2,y2};
     circles.push_back(circle);
     curves.push_back(curve);
     lines.push_back(line);
     break;
     }
     break;
     case SDL_MOUSEMOTION:
     if (drawing)
     {
     x2 = PrimerBoton.motion.x;
     y2 = PrimerBoton.motion.y;
     }
     break;
     case SDL_QUIT:
     quit = true;
     break;
     } 
     }
 if (x1 >= 0 && x2 <= 125 && y1 >= 0 && y2 <=100)
 {
boton1 = true; boton2 = false; boton3 = false;boton4 = false;
            }
if (x1 >= 125 && x2 <= 250 && y1 >= 0 && y2 <= 100)
            {
boton1 = false;boton2 = true;boton3 = false; boton4 = false;
            }
if (x1 >= 250 && x2 <= 375 && y1 >= 0 && y2 <= 100)
            {
boton1 = false; boton2 = false;boton3 = true; boton4 = false;
            }
if (x1 >= 375 && x2 <= 500 && y1 >= 0 && y2 <= 100)
            {
color = 1;
            }
if (x1 >= 500 && x2 <= 625 && y1 >= 0 && y2 <= 100)
            {
	lines.clear();
            }
if (x1 >= 625 && x2 <= 750 && y1 >= 0 && y2 <= 100)
            {
	circles.clear();
            }
if (x1 >= 750 && x2 <= 872 && y1 >= 0 && y2 <= 100)
            {
	curves.clear();
            }
if (x1 >= 875 && x2 <= 1000 && y1 >= 0 && y2 <= 100)
            {
              
	color = 3;

}
                                                   
DrawPlain();
			

if (boton1 == true)
{
for (std::list<Line>::const_iterator i = lines.begin(); i != lines.end(); ++i)
{
Line line = *i;
Bresenham(line.x1, line.y1, line.x2, line.y2);
}
            }
            if (boton2 == true)
            {
            for (std::list<Circles>::const_iterator i = circles.begin(); i != circles.end(); ++i)
            {
            Circles circles = *i;
            Circulo(circles.x2-circles.x1, circles.x1, circles.y1);
                    
            }
            }
            if (boton3 == true)
            {
            for (std::list<Line>::const_iterator i = lines.begin(); i != lines.end(); ++i)
            {
            Line line = *i;
            BezierCurve(Vector2(x1, y1), Vector2(x2, y2), Vector2(0, 0), Vector2(0, 0));
            }
            }
			if (boton4 == true)
			{
			for 
			(std::list<Circles>::const_iterator i = circles.begin(); i != circles.end(); ++i)
			{
			Circles circles = *i;
			Circulo(circles.x2 - circles.x1, circles.x1, circles.y1);

			}
			}
			std::cout << "";
			std::vector<Vector2> PrimerBoton = std::vector<Vector2>(4);
			PrimerBoton[0] = Vector2(0, 0);
			PrimerBoton[1] = Vector2(1000, 0);
			PrimerBoton[2] = Vector2(1000,100);
			PrimerBoton[3] = Vector2(0, 100);
			std::vector<Vector2> Linea1 = std::vector<Vector2>(2);
			Linea1[0] = Vector2(125, 0);
			Linea1[1] = Vector2(125, 100);
			std::vector<Vector2> Linea2 = std::vector<Vector2>(2);
			Linea2[0] = Vector2(250, 0);
			Linea2[1] = Vector2(250, 100);
			std::vector<Vector2> Linea3 = std::vector<Vector2>(2);
			Linea3[0] = Vector2(375, 0);
			Linea3[1] = Vector2(375,100);
			std::vector<Vector2> Linea4 = std::vector<Vector2>(2);
			Linea4[0] = Vector2(500, 0);
			Linea4[1] = Vector2(500, 100);
			std::vector<Vector2> Linea5 = std::vector<Vector2>(2);
			Linea5[0] = Vector2(625, 0);
			Linea5[1] = Vector2(625, 100);
			std::vector<Vector2> Linea6 = std::vector<Vector2>(2);
			Linea6[0] = Vector2(750, 0);
			Linea6[1] = Vector2(750, 100);	
			std::vector<Vector2> Linea7 = std::vector<Vector2>(2);
			Linea7[0] = Vector2(875, 0);
			Linea7[1] = Vector2(875, 100);
			
			
            
        
           VectorCuadrado(PrimerBoton);
            VectorCuadrado(Linea1);
            VectorCuadrado(Linea2);
            VectorCuadrado(Linea3);
            VectorCuadrado(Linea4);
            VectorCuadrado(Linea5);
            VectorCuadrado(Linea6);
            VectorCuadrado(Linea7);
     
         
         
    
            SDL_RenderPresent(gRenderer);
              SDL_RenderClear(gRenderer);
        }

    }
	

    close();
    return 0;
}
void quit()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
}
void CUADRADO(int r, int xc, int yc)
{

	int Punto, x, y;
	Punto = 1 - r;
	x = 0;
	y = r;
	if (color == 1)
	{
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	}
	else if (color == 2)
	{
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x4f, 0x3F, 0x5F);
	}
	else if (color == 3)
	{
		SDL_SetRenderDrawColor(gRenderer, 12, 14, 128, 0);
	}
	else if (color == 4)
	{
		SDL_SetRenderDrawColor(gRenderer, 128, 12, 89, 0);
	}

	for (; x <= y;)
	{
		if (Punto <= 0)
		{
			x = x + 1;
			y = y;
			Punto = Punto + (4 * x) + 6;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			Punto = Punto + 4 * (x - y) + 10;
		}

		SDL_RenderDrawPoint(gRenderer, x + xc, y + yc);
		SDL_RenderDrawPoint(gRenderer, -x + xc, y + yc);
		SDL_RenderDrawPoint(gRenderer, -x + xc, -y + yc);
		SDL_RenderDrawPoint(gRenderer, x + xc, -y + yc);
		SDL_RenderDrawPoint(gRenderer, y + xc, x + yc);
		SDL_RenderDrawPoint(gRenderer, -y + xc, x + yc);
		SDL_RenderDrawPoint(gRenderer, -y + xc, -x + yc);
		SDL_RenderDrawPoint(gRenderer, y + xc, -x + yc);


	}

}
