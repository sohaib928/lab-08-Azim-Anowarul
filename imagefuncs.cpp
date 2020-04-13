#include "imagefuncs.h"
#include "imagehelpers.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

//Task A
void invert(std::string image)
{
  int h, w;
  int tsk1[MAX_H][MAX_W];
  int outimg[MAX_H][MAX_W];
  readImage(image, tsk1, h, w);
  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
      outimg[i][j]=255-tsk1[i][j];
    }
  }
  writeImage("taska.pgm", outimg, h, w);
}


//Task B
void invertHalf(std::string image)
{
  int tsk2[MAX_H][MAX_W];
  int outImg[MAX_H][MAX_W];
  int h, w;
  readImage(image, tsk2, h, w);

  for(int i= 0; i < h; i++)
  {
    for(int j = 0; j < w/2; j++)
    {
      outImg[i][j] = tsk2[i][j];
    }
    for(int k = w/2; k < w; k++)
    {
      outImg[i][k] = 255 - tsk2[i][k];
    }
  }
  writeImage("taskb.pgm", outImg, h, w);
}


//Task C
void whiteBox(std::string image)
{
  int tsk3[MAX_H][MAX_W];
  int outImg[MAX_H][MAX_W];
  int h, w;
  readImage(image,tsk3, h, w);

  for(int i = 0; i< h/4; i++)
  {
    for(int j = 0; j < w; j++)
      outImg[i][j] = tsk3[i][j];
  }

  for(int i = h/4; i< (3*h)/4; i++)
  {
    for(int j = 0; j< w/4; j++)
      outImg[i][j] = tsk3[i][j];

    for(int j= w/4; j< (3*w)/4; j++)
      outImg[i][j] = 255;

    for(int j = (3*w)/4; j < w; j++)
      outImg[i][j] = tsk3[i][j];
  }
  for(int i= (3*h)/4; i < h; i++)
  {
    for(int j = 0; j< w; j++)
      outImg[i][j] = tsk3[i][j];
  }
  writeImage("taskc.pgm",outImg, h, w);
}



//Task D
void frame(std::string image)
{
  int outImg[MAX_H][MAX_W], tsk4[MAX_H][MAX_W];
  int h,w;
  readImage(image,tsk4, h, w);

	for(int row = 0; row < h; row++)
  {
		for(int col = 0; col < w; col++)
			outImg[row][col] = tsk4[row][col];
	}
	for(int col = w/4; col < w-w/4; col++){
		outImg[h/4][col] = 255;
	}
	for(int col = w/4; col < w-w/4; col++){
		outImg[h-h/4][col] = 255;
	}
	for(int row = h/4; row < h-h/4; row++){
		outImg[row][w/4] = 255;
	}
	for(int row = h/4; row < h-h/4; row++){
		outImg[row][w-w/4] = 255;
	}
  writeImage("taskd.pgm",outImg, h, w);
}


//TASK E
void scale(std::string image){
	int outImg[MAX_H][MAX_W], tsk5[MAX_H][MAX_W];
  int h, w;
  readImage(image,tsk5, h, w);

	for(int i= 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			outImg[i*2][j*2] = tsk5[i][j];
			outImg[i*2+1][j*2] = tsk5[i][j];
			outImg[i*2][j*2+1] = tsk5[i][j];
			outImg[i*2+1][j*2+1] = tsk5[i][j];
		}
	}
  writeImage("taske.pgm",outImg, h*2, w*2);
}

//TASK F
void pixelate(std::string image){
	int outImg[MAX_H][MAX_W], tsk6[MAX_H][MAX_W];
  int h, w;
  readImage(image,tsk6, h, w);

	for(int i = 0; i< h; i+=2) {
		for(int j= 0; j< w; j+=2) {
			int sum = 0;
			sum += tsk6[i][j];
			sum += tsk6[i+1][j];
			sum += tsk6[i][j+1];
			sum += tsk6[i+1][j+1];
			int avg = sum/4;
			outImg[i][j] = avg;
			outImg[i+1][j] = avg;
			outImg[i][j+1] = avg;
			outImg[i+1][j+1] = avg;
		}
	}
  writeImage("taskf.pgm",outImg, h, w);
}
