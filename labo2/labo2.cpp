///////
// Auteurs: Samuel Harvey et Simon Dumas
// Date: 5 octobre 2022
// 
// Description: Module python servant � ex�cuter un programme �crit en c++ servant � effectuer la lecture d'un fichier vid�o. Le programme c++ inclut aussi les fonctionnalit�s de play/pause (P), avance rapide (A), retour au d�but (R) et quitter pour fermer l'application (Q).
// Le module python prend en entr�e le path d'une vid�o et la lit avec les fonctionnalit�s de contr�le pr�sentes dans le programme initial �crit en c++.
////////

//labo2.cpp est inspir� du fichier du nom de main.cpp trouv� sur Moodle � la remise du projet pr�c�dent, lui m�me tir� du code trouv� � l'adresse: https://docs.microsoft.com/fr-fr/windows/win32/directshow/how-to-play-a-file
//Le fichier main.cpp avait �t� modifi� lors du premier laboratoire de ce cours et a �t� r�utilis� dans le cadre de ce second laboratoire. Celui-ci a �t� modifi� afin que le code puisse �tre 
//ex�cut� dans un module python avec en entr�e le path de la vid�o � jouer.

#include "Lecture.h"

Lecture Lec;

static PyObject* start(PyObject* self, PyObject* args)
{
    const char* buffer;
    PyArg_ParseTuple(args, "s", &buffer);
    string buffpath = buffer;
    wstring temp(buffpath.begin(), buffpath.end());
    wstring autre = temp;
    LPCWSTR path = autre.c_str();;
    
    PyObject* valeur;
    valeur = Lec.start(self,args);
    Lec.hr = Lec.pGraph->RenderFile(path, NULL);

    if (SUCCEEDED(Lec.hr))
    {
        // Run the graph.
        Lec.play();
        if (SUCCEEDED(Lec.hr))
        {
            Lec.setEndTime();
            Lec.Message = "Methode bien fermee!";
            const char* buf = Lec.Message.c_str();
            valeur = PyBytes_FromString(buf);
            return valeur;
        }
        cout << "Probleme de lecture..." << endl;
        Lec.Message = "Probleme de lecture...";
        const char* buf2 = Lec.Message.c_str();
        valeur = PyBytes_FromString(buf2);
        Lec.~Lecture();
        return valeur;
    }
    else
    {
        cout << "Probleme d'ouverture du fichier video..." << endl;
        Lec.Message = "Probleme d'ouverture du fichier video...";
        const char* buf3 = Lec.Message.c_str();
        valeur = PyBytes_FromString(buf3);
        Lec.~Lecture();
        return valeur;
    }
}

static PyObject* play(PyObject* self, PyObject* args)
{
    PyObject* valeur;
    Lec.play();
    Lec.Message = "Methode bien fermee!";
    const char* buf = Lec.Message.c_str();
    valeur = PyBytes_FromString(buf);
    return valeur;
}

static PyObject* pause(PyObject* self, PyObject* args)
{
    PyObject* valeur;
    Lec.pause();
    Lec.Message = "Methode bien fermee!";
    const char* buf = Lec.Message.c_str();
    valeur = PyBytes_FromString(buf);
    return valeur;
}

static PyObject* fastforward(PyObject* self, PyObject* args)
{
    PyObject* valeur;
    Lec.fastforward();
    Lec.Message = "Methode bien fermee!";
    const char* buf = Lec.Message.c_str();
    valeur = PyBytes_FromString(buf);
    return valeur;
}

static PyObject* rewind(PyObject* self, PyObject* args)
{
    PyObject* valeur;
    Lec.rewind();
    Lec.Message = "Methode bien fermee!";
    const char* buf = Lec.Message.c_str();
    valeur = PyBytes_FromString(buf);
    return valeur;
}

static PyObject* quit(PyObject* self, PyObject* args)
{
    PyObject* valeur;
    Lec.~Lecture();
    Lec.Message = "Methode bien fermee!";
    const char* buf = Lec.Message.c_str();
    valeur = PyBytes_FromString(buf);
    return valeur;
}

static PyMethodDef methods[] = {

    
    {"start",start,METH_VARARGS,"start"},
    {"play",play,METH_NOARGS,"play"},
    {"pause",pause,METH_NOARGS,"pause"},
    {"fastforward",fastforward,METH_NOARGS,"fastforward"},
    {"rewind",rewind,METH_NOARGS,"rewind"},
    {"quit",quit,METH_NOARGS,"quit"},
    { NULL, NULL, 0, NULL }
};

static struct PyModuleDef labo2 =
{
    PyModuleDef_HEAD_INIT,
    "labo2", /* name of module */
    "module servant a faire jouer une video et controler sa lecture",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    methods
};

PyMODINIT_FUNC PyInit_labo2(void)
{
    return PyModule_Create(&labo2);
}