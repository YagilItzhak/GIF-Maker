/*********************************
* Class: MAGSHIMIM Final Project *
* Play function				 	 *
**********************************/

#include "view.h"

/**
play the movie!!
display the images each for the duration of the frame one by one and close the window
input: a linked list of frames to display
output: none
**/
void play(const char* title, FrameNode* list)
{
	if (list)
	{
		cvNamedWindow(title, CV_WINDOW_AUTOSIZE); //create a window
		FrameNode* head = list;
		size_t imgNum = 1, playCount = 0;
		IplImage* image;
		while (playCount < GIF_REPEAT)
		{
			while (list)
			{
				image = cvLoadImage(list->frame->path, 1);
				IplImage* pGrayImg = 0;
				pGrayImg = cvCreateImage(cvSize(image->width, image->height), image->depth, 1);
				if (!image) //The image is empty - shouldn't happen since we checked already.
				{
					printf("Could not open or find image number %d", imgNum);
				}
				else
				{
					cvShowImage(title, image); //display the image
					cvWaitKey(list->frame->duration); //wait
					list = list->next;
					cvReleaseImage(&image);
				}
				imgNum++;
			}
			list = head; // rewind
			playCount++;
		}
		cvDestroyWindow("Display window");
	}
	return;
}