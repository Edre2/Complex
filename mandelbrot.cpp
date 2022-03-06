#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define OLC_PGE_APPLICATION

#include "olcPixelGameEngine.h"
#include "complex.h"

const int SIZE_X = 800;
const int SIZE_Y = 800;
const int PIX_SIZE = 1;

// FOR THE MANDELBROT :
const double MIN_X = -2;
const double MAX_X = 2;
const double MIN_Y = -2;
const double MAX_Y = 2;

/*const double MIN_X = -1;
const double MAX_X = 0;
const double MIN_Y = -1;
const double MAX_Y = 0;*/

const int MAX_ITERATIONS = 100;
const int MY_INFINITY = 16;

double map(double nb, double min, double max, double min_arrive, double max_arrive)
{
    // Un nb entre 0 et 1
   return (nb - min) / (max -min) * (max_arrive - min_arrive) + min_arrive;
}

class Mandelbrot : public olc::PixelGameEngine
{
	public:
		Mandelbrot() : a(0,0), points(SIZE_X , std::vector<int>(SIZE_Y, 0))
		{

			sAppName = "Mandelbrot set";

            for(double i = 0; i < SIZE_X; i++)
                for(double j = 0; j < SIZE_Y; j++)
                {
                    //a = MyComplex(i / SIZE_X*(MIN_X+MAX_X) - MIN_X, j / SIZE_X*(MIN_Y+MAX_Y) - MIN_Y);
                    a = MyComplex(map(j, 0, SIZE_Y, MIN_Y, MAX_Y), map(i, 0, SIZE_X, MIN_X, MAX_X));

                    MyComplex z(0,0);

                    int n = 0;

                    for(n = 0; n < MAX_ITERATIONS; n++)
                    {
                        z = z * z + a;
                        if(z.re() + z.im() > MY_INFINITY || z.re() + z.im() < -MY_INFINITY)
                            break;
                    }

                    points[i][j] = (double(n) / (MAX_ITERATIONS-1)) * 255;
                    Draw(i, j, olc::Pixel(points[i][j],points[i][j],points[i][j]));
                }            
		};

	public:
		bool OnUserCreate() override
		{

			// Called once at the start, so create things here
			return true;
		};

		bool OnUserUpdate(float fElapsedTime) override
		{
			/*for(int i = 0; i < SIZE_X; i++)
                for(int j = 0; j < SIZE_Y; j++)
                {
                    //std::cout << i << " " << j << "\n";
                    std::cout << points[i][j] << "\n";
                    //Draw(i, j, olc::Pixel(points[i][j],points[i][j],points[i][j]));
                }*/


            for(double i = 0; i < SIZE_X; i++)
                for(double j = 0; j < SIZE_Y; j++)
                    Draw(i, j, olc::Pixel(points[i][j],points[i][j],points[i][j]));

			return true;
		};

	private:
        MyComplex a;
        std::vector<std::vector<int>> points;

};


int main()
{
	bool fullscreen = false;
	Mandelbrot demo;
	if (demo.Construct(SIZE_X, SIZE_Y, PIX_SIZE, PIX_SIZE, fullscreen, true))
		demo.Start();

	return 0;
}
