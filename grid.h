#ifndef __GRID_H__
#define __GRID_H__

#include <array>

class Grid
{

 private:
  int m_tick;
  
  typedef std::array<bool,10> SingleDimType;
  typedef std::array<SingleDimType,10> TwoDimType;
 
  TwoDimType m_grid;
  TwoDimType m_nextGrid;

  void seed(void);

  int compute_population(int x, int y);

 public:

  void start(void);
  void tick(void);
  void print(void);


  Grid();

};

#endif
