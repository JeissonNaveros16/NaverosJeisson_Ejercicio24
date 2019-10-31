#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>

float gaussian(float x, float sigma);
float gauss_metropolis(float sigma, float aleatorio, float alpha, float anterior, float pi);

int main()
{
	int i;
	float pi = 2.0*asin(1.0);
	float sigma = 1.0;
	srand48(8);
	float anterior = drand48();
	
	for (i=0;i<10000;i++)
	{
		float aleatorio = drand48() - 0.5;
		float alpha = drand48();
		float resp = gauss_metropolis( sigma, aleatorio, alpha, anterior, pi );
		std::cout << resp << std::endl;
		anterior = resp;
	}
  
  return 0;
}


float gaussian(float x, float sigma, float pi)
{
	return exp(-(x*x)/(2.0*sigma*sigma))/sqrt(2.0*pi*sigma*sigma);
}
 
float gauss_metropolis(float sigma, float aleatorio, float alpha, float anterior, float pi)
{
	float propuesta = anterior + aleatorio;
	float temp = gaussian(propuesta, sigma, pi)/gaussian(anterior, sigma, pi);
	float r = 0;
	if(1 < temp)
	{
		r = 1;
	}
	else
	{
		r = temp;
	}
    if(alpha < r)
	{
		return propuesta;
	}
	else
	{
		return anterior;
	}
}