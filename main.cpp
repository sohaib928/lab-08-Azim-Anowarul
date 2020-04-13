#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imagefuncs.h"
#include "imagehelpers.h"


int main()
{
  invert("inImage.pgm");
  invertHalf("inImage.pgm");
  whiteBox("inImage.pgm");
  frame("inImage.pgm");
  scale("inImage.pgm");
  pixelate("inImage.pgm");
  return 0;
}
