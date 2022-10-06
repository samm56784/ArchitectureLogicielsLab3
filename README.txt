INSTRUCTIONS À SUIVRE 

***À noter que le projet a été développé pour Python 3.10 à la base, les autres versions n'ont pas été testées, mais le tout devrait fonctionner tout de même si la version est assez récente (Python 3.X).

1. Téléchargez la vidéo voulue sur votre ordinateur et noter l'emplacement de celle-ci

2. Installer la version la plus récente de Python sur votre ordinateur en retenant son emplacement dans les fichiers

3. Aller chercher le projet sur github au lien suivant-> https://github.com/samm56784/ArchitectureLogicielsLab3

4. Enregistrer le projet sur l'ordinateur et l'ouvrir

5. Aller dans les propriétés du projet, en haut de la fenêtre, changer la configuration pour le mode Release et la plateforme pour x64

6. Dans les propriétés générales, mettre le nom de la cible comme étant labo2 et mettre le type de configuration en .dll

7. Toujours dans les propriétés, dans les paramètres avancés, mettre l'entension du fichier cible en .pyd

8. Encore dans les propriétés, dans les répertoires VC++, ajouter dans les répertoires Include, l'emplacement de sauvegarde de la bibliothèque include de Python (ex-> C:/Python310/include) et ajouter également dans les répertoires de bibliothèques, l'emplacement de sauvegarde de la bibliothèque de Python (ex-> C:/Python310/libs)

9. Aller dans le fichier exec.py sur Visual Studio et changer la ligne où c'est écrit sys.path.append("...") et changer entre les guillemets le path pour celui où se trouve le ficher .pyd du labo (normalement dans x64/Release)

10. Nettoyer, compiler et générer votre solution par la suite dans le mode Release X64

11. Ouvrir Powershell et aller chercher le projet dans vos fichiers grâce à la commande "cd"

12. Lorsque vous serez dans le fichier de votre labo, inscrivez: py exec .py

13. Un interface s'ouvrira et vous devrez cliquer sur le bouton "Ouvrir un fichier"

14. Vous serez alors invité à aller chercher dans vos fichiers votre vidéo que vous avez sauvegardé auparavant puis la sélectionner

15. Votre vidéo commencera et vous pourrez contrôler votre vidéo à partir des boutons de l'interface graphique (Play,Pause,Avance rapide(1,25x),Retour au debut et Quit)
