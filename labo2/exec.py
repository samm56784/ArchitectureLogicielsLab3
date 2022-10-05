import sys
import os                               # importing the os module  
import shutil                           # importing the shutil module  
from tkinter import *
from tkinter import filedialog as fd
from tkinter import messagebox as mb    # importing the messagebox module from tkinter  
from tkinter import ttk
#sys.path.append("C:/Users/PC/Desktop/Labo2/ArchitectureLogicielsLab2/x64/Release")#Changer le path vers le path de votre labo2.py
sys.path.append("C:/Users/sharvey27/Desktop/Lab2/ArchitectureLogicielsLab2/x64/Release")
import labo2
#print('path:')
#path = input();
#labo2.start(path)

def openFile():  
   # selecting the file using the askopenfilename() method of filedialog  
   the_file = fd.askopenfilename(  
      title = "Select a file of any type",  
      filetypes = [("All files", "*.*")]  
      )  
   labo2.start(the_file)
   # opening a file using the startfile() method of the os module  
   #os.startfile(os.path.abspath(the_file))  
def play():
    labo2.play()

def pause():
    labo2.pause()


def fastforward():
    labo2.fastforward()

def rewind():
    labo2.rewind()

root = Tk()
frm = ttk.Frame(root, padding = 10)
frm.grid()
root.title('Labo3')
ttk.Button(frm, text="Ouvrir un fichier",command=openFile).grid(column=1,row=0)
ttk.Button(frm, text="Play",command=play).grid(column=2,row=0)
ttk.Button(frm, text="Pause",command=pause).grid(column=3,row=0)
ttk.Button(frm, text="Avance rapide (1,25x)",command=fastforward).grid(column=4,row=0)
ttk.Button(frm, text="Retour au debut",command=rewind).grid(column=5,row=0)
ttk.Button(frm, text="Quit",command=root.destroy).grid(column=6,row=0)

root.mainloop() 





#C:\\Examples.avi