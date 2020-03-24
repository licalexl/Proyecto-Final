//#include "circulo.h"
//#include "main.h"
//
//
//void Circulo(int r, int xc, int yc)
//{
//
//	int Punto, x, y;
//	Punto = 1 - r;
//	x = 0;
//	y = r;
//	if (color == 1)
//	{
//		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
//	}
//	else if (color == 2)
//	{
//		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x4f, 0x3F, 0x5F);
//	}
//	else if (color == 3)
//	{
//		SDL_SetRenderDrawColor(gRenderer, 12, 14, 128, 0);
//	}
//	else if (color == 4)
//	{
//		SDL_SetRenderDrawColor(gRenderer, 128, 12, 89, 0);
//	}
//
//	for (; x <= y;)
//	{
//		if (Punto <= 0)
//		{
//			x = x + 1;
//			y = y;
//			Punto = Punto + (4 * x) + 6;
//		}
//		else
//		{
//			x = x + 1;
//			y = y - 1;
//			Punto = Punto + 4 * (x - y) + 10;
//		}
//		SDL_RenderDrawPoint(gRenderer, x + xc, y + yc);
//		SDL_RenderDrawPoint(gRenderer, -x + xc, y + yc);
//		SDL_RenderDrawPoint(gRenderer, -x + xc, -y + yc);
//		SDL_RenderDrawPoint(gRenderer, x + xc, -y + yc);
//		SDL_RenderDrawPoint(gRenderer, y + xc, x + yc);
//		SDL_RenderDrawPoint(gRenderer, -y + xc, x + yc);
//		SDL_RenderDrawPoint(gRenderer, -y + xc, -x + yc);
//		SDL_RenderDrawPoint(gRenderer, y + xc, -x + yc);
//
//
//	}
//
//}
//
//
