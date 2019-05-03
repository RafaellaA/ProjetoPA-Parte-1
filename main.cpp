#include <iostream>
#include "sculptor.h"

using namespace std;

int main(void)
{

  Sculptor e(2,2,2);
  e.setColor(0, 1, 0, 1);
  e.putVoxel(0,0,0);
  e.setColor(1, 0, 0, 1);
  e.putVoxel(1,0,0);
  e.setColor(1, 0, 1, 0.8);
  e.putVoxel(0,1,0);
  
  return 0;
}
