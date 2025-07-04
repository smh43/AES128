# AES128

Pour l'instant ce projet ne contient pas de constante RCON, ni de Rotword au moment de la génération de keys

Avant même de commencer à chiffrer, on doit s'assurer que la taille du message est un multiple de 16
Si il ne l'est pas, on rajoute des octets jusqu'à ce qu'il le soit
La méthode utilisé est PCKS7, qui rajoute des octets dont leurs valeur est le nombre d'octets manquants

*ex: "Bonjour" - > "Bonjour\0x0a\0x0a\0x0a\0x0a\0x0a\0x0a\0x0a\0x0a\0x0a\0x0a"*

Et si le message a déjà une taille multiple de 16, on rajoute 16 octets pour le dépadding

-----------------------------------------------------------------------------------------------

## AES128 fonctionne par bloc, en matrice de 4*4 octets
Il se base essentiellement sur le Xor
Il génère 10 clés de chiffrement chacun dérivé de la précédente

### Pour chaque matrice, il va:

changer la valeur de chaque octet selon un tableau subByte en fonction de leur valeur:

*ex : 0x38 -> subByteTab[3][8]*

Decaler les lignes

Mixer les colonnes avec la formule de Rijndael

Et Xor chaque octet avec l'octet de la clé à son index:

ex:

[1 2 3 4] | [F E D 0]
_____________________
[5 6 7 8] | [C B A 9]
_____________________
[9 A B C] | [8 7 6 5]
_____________________
[0 D E F] | [4 3 2 1]

1 sera xor avec F, 2 avec E, 3 avec D etc...
Ces etapes vont se répéter 9 fois, avec la clé qui change à chaque tour
Pour la 10ème étape, c'est pareil mais on ne mixe pas les colonnes

et la le message est chiffré et presque incassable



[Vidéo Explicative](https://www.youtube.com/watch?v=gP4PqVGudtg)
 
