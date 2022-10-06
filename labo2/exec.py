import sys
import os                               # importing the os module  
import shutil                           # importing the shutil module 
from tkinter import *
from tkinter import filedialog as fd
from tkinter import messagebox as mb    # importing the messagebox module from tkinter  
from tkinter import ttk
from tkinter import Tk
from tkinter.constants import DISABLED, NORMAL
from tkinter.ttk import Button, Label
sys.path.append("C:/Users/PC/Desktop/Labo2/ArchitectureLogicielsLab3/x64/Release")#Changer le path vers le path de votre labo2.py
#sys.path.append("C:/Users/Utilisateur/Projets Universite/Labo3/ArchitectureLogicielsLab3/x64/Release")
import labo2
import tkinter as tk
 
def switchButtonState():
    the_file = fd.askopenfilename(  
      title = "Select a file of any type",  
      filetypes = [("All files", "*.*")]  
      )  
    labo2.start(the_file)
    if (button1['state'] == tk.NORMAL):
        button1['state'] = tk.DISABLED
    else:
        button1['state'] = tk.NORMAL
    if (button2['state'] == tk.NORMAL):
        button2['state'] = tk.DISABLED
    else:
        button2['state'] = tk.NORMAL
    if (button3['state'] == tk.NORMAL):
        button3['state'] = tk.DISABLED
    else:
        button3['state'] = tk.NORMAL
    if (button4['state'] == tk.NORMAL):
        button4['state'] = tk.DISABLED
    else:
        button4['state'] = tk.NORMAL
    if (button5['state'] == tk.NORMAL):
        button5['state'] = tk.DISABLED
    else:
        button5['state'] = tk.NORMAL
 

def play():
    labo2.play()

def pause():
    labo2.pause()

def fastforward():
    labo2.fastforward()

def rewind():
    labo2.rewind()

def quit():
    labo2.quit()
    app.destroy()

app = tk.Tk()
app.title('Labo3')
button1 = tk.Button(app, text="Ouvrir un fichier",state=tk.NORMAL,command = switchButtonState)
button1.grid(row=0,column=1)
button2 = tk.Button(app, text="Play",state=tk.DISABLED,command = play)
button2.grid(row=0,column=2)
button3 = tk.Button(app, text="Pause",state=tk.DISABLED,command = pause)
button3.grid(row=0,column=3)
button4 = tk.Button(app, text="Avance rapide (1,25x)",state=tk.DISABLED,command = fastforward)
button4.grid(row=0,column=4)
button5 = tk.Button(app, text="Retour au debut",state=tk.DISABLED,command = rewind)
button5.grid(row=0,column=5)
button6 = tk.Button(app, text="Quitter",state=tk.NORMAL,command = quit)
button6.grid(row=0,column=6)
 
app.mainloop()

