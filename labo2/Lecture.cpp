#include "Lecture.h"

Lecture::Lecture()
{
    État = INITIAL;
    rtNow = 0;
    pGraph = NULL;
    pControl = NULL;
    pEvent = NULL;
    pSeeking = NULL;
}


void Lecture::start()
{
    hr = CoInitialize(NULL);

    if (FAILED(hr))
    {
        printf("ERROR - Could not initialize COM library");
    }

    // Create the filter graph manager and query for interfaces.
    hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
        IID_IGraphBuilder, (void**)&pGraph);
    if (FAILED(hr))
    {
        printf("ERROR - Could not create the Filter Graph Manager.");
    }

    hr = pGraph->QueryInterface(IID_IMediaControl, (void**)&pControl);
    hr = pGraph->QueryInterface(IID_IMediaEvent, (void**)&pEvent);
    hr = pGraph->QueryInterface(IID_IMediaSeeking, (void**)&pSeeking);

}

void Lecture::play()
{
    hr = pControl->Run();
    cout << "P - Play\n";
    État=PLAYING;
}

void Lecture::pause()
{
    hr = pControl->Pause();
    cout << "P - Pause\n";
    État = PAUSED;
}

void Lecture::fastforward()
{
    hr = pSeeking->SetRate(1.25);
    cout << "A - Avance rapide (1,25x)\n";
    État = PLAYING;
}

void Lecture::rewind()
{

    hr = pSeeking->SetRate(1.0);
    hr = pSeeking->SetPositions(&rtNow, AM_SEEKING_AbsolutePositioning, &rtEnd, AM_SEEKING_AbsolutePositioning);
    hr = pControl->Run();
    cout << "R - Retour au debut\n";
    État = PLAYING;
}

void Lecture::quit()
{
    cout << "Q - QUIT\n";
    État = STOPPED;
}

void Lecture::setEndTime()
{
    hr = pSeeking->GetPositions(NULL, &rtEnd);
}


Lecture::~Lecture()
{
    pControl->Release();
    pEvent->Release();
    pGraph->Release();
    pSeeking->Release();
    CoUninitialize();
}