#pragma once
#pragma once
#pragma comment(lib,"Strmiids.lib")
#include <dshow.h>
#include <iostream>
#include <Python.h>
#include <conio.h>
using namespace std;
enum state
{
	INITIAL,PLAYING, PAUSED, STOPPED,QUIT
};

class Lecture
{
public:
	state État;
	IGraphBuilder* pGraph;
	IMediaControl* pControl;
	IMediaEvent* pEvent;
	IMediaSeeking* pSeeking;
	string Message;
	HRESULT hr;
	Lecture();
	void start();
	void play();
	void pause();
	void fastforward();
	void rewind();
	void quit();
	void  setEndTime();
	~Lecture();

private:
	REFERENCE_TIME rtNow = 0, rtEnd;
};