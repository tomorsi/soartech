
#include "grid.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Grid::Grid() 
    :m_tick(0)
{
    // seed random number generated. 
    std::srand(std::time(0));
    seed();
}

void Grid::seed()
{
    for (auto i = m_grid.begin(); i != m_grid.end(); i++)
    {
	SingleDimType jj = *i;
	for (auto j = jj.begin(); j != jj.end(); j++)
	{
	    *j = std::rand()%5>1?true:false;
	}
    }    
}

void Grid::start(void)
{
    while(m_tick < 10)
    {
	Grid::tick();
	m_grid = m_nextGrid;
	Grid::print();
    }
}

void Grid::tick()
{
    m_nextGrid = m_grid;
    
    for (int x = 0 ; x < 10; x++)
    {
	for (int y = 0; y < 10; y++)
	{
	    int population = compute_population(x, y);
	    if (m_grid[x][y] == true && population < 2)
	    {
		m_nextGrid[x][y] = false;
	    }
	    if ( (m_grid[x][y] == true && population == 2 ) || (m_grid[x][y] == true && population == 3))
	    {
		// live another day, possibly assert?
	
	    }
	    if ( m_grid[x][y] == true && population > 3)
	    {
		// overpopulation
		m_nextGrid[x][y] = false;
	    }
	    if ( m_grid[x][y] == false && population == 3)
	    {
		// reproduce
		m_nextGrid[x][y] = true;
	    }
	}
    }

}

int Grid::compute_population(int x, int y)
{
    // std::cout << "computing population of(" << x << "," << y << ")" << std::endl;

    int population = 0;
    for (int i = -1; i<2; i++)
    {
	for (int k = -1; k<2; k++)
	{
	    if (k == 0 && i == 0)
		continue;

	    if ( ( (x+i)>-1 && (x+i)<10) && ((y+k)>-1 && (y+k)<10))
		population += m_grid[x+i][y+k]?1:0;
	      
	}
    }
    return population;
}

void Grid::print()
{
    std::cout << "tick: " << m_tick++ << std::endl;

    for (int i= 0; i < 10; i++)
    {
	std::cout << std::endl;
	for (int j = 0; j < 10 ; j++)
	{
	    std::cout << m_grid[i][j] << " " ;
	}
    }
    std::cout << std::endl << std::endl;
}

int main(void)
{
    Grid grid;
    grid.start();

    return 0;
}
