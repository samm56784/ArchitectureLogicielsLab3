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


PyObject* Lecture::start(PyObject* self, PyObject* args)
{
    const char* buffer;
    PyObject* val;
    PyArg_ParseTuple(args, "s", &buffer);
    string buffpath = buffer;
    wstring temp(buffpath.begin(), buffpath.end());
    wstring autre = temp;
    LPCWSTR path = autre.c_str();
    hr = CoInitialize(NULL);

    if (FAILED(hr))
    {
        printf("ERROR - Could not initialize COM library");
        return NULL;
    }

    // Create the filter graph manager and query for interfaces.
    hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
        IID_IGraphBuilder, (void**)&pGraph);
    if (FAILED(hr))
    {
        printf("ERROR - Could not create the Filter Graph Manager.");
        Message = "Probleme de creation de l'instance direct show";
        const char* buf3 = Message.c_str();
        val = PyBytes_FromString(buf3);
        return val;
    }

    hr = pGraph->QueryInterface(IID_IMediaControl, (void**)&pControl);
    hr = pGraph->QueryInterface(IID_IMediaEvent, (void**)&pEvent);
    hr = pGraph->QueryInterface(IID_IMediaSeeking, (void**)&pSeeking);

    // Build the graph, path étant le path complet de la vidéo que l'on a reçue en entrée du module start()-> ex: labo2.start("C:\\a\\Example.avi")
    

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

REFERENCE_TIME Lecture::getEndTime()
{
    return rtEnd;
}


Lecture::~Lecture()
{
    pControl->Release();
    pEvent->Release();
    pGraph->Release();
    pSeeking->Release();
    CoUninitialize();
}