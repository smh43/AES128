# AES128

Test de AES128 mode ECB fait main, différe surement des algorithmes officiels surtout dans la génération des clés je crois


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

Décaler les lignes

Mixer les colonnes avec la formule de Rijndael

La formule de Rijndael permet simplement de multiplier chaque colonne par une matrice de coefficient :

[2 3 1 1]    \[c[0]
_________     
[1 2 3 1]     c[1]
_________  
[1 1 2 3]     c[2]
_________
[3 1 1 2]     c[3]\]

La multiplication matricielle fait multiplier les colonnes par les lignes

ex : out[0] = c[0]*1 ^ c[1]*3 ^ c[2]*1 ^ c[3]*1, 
     out[1] = c[0]*1 ^ c[1]*2 ^ etc... 

Mais la particularité est que le calcul se fait dans un champ fini, de [0; 0xff] (un octet)

Le mixColumn se base sur un polynome de degré 8:
x\**8 + x\**4 + x**3 + x + 1

Dans le champ [0; 0xff].
Dans un champ de puissance de 2, les additions sont en fait des xor (a + b % 2) = a ^ b pour a et b dans [0; 1]

ce qui donne en binaire 0000 0001 0001 1011 = 0x11B

ce qui revient à x**8 + 0x1B

donc si la valeur de la multiplication dépasse 8 bits (donc x**8 > 0), on le ramène dans le champ par un xor 0x1B

Une multiplication est ici représenté par un décalage de 1 bit vers la gauche (a << 1)

la fonction xtime() permet de multiplier dans ce champ correctement

C'est compliqué et avancé donc voilà Wikipédia pour mieux expliquer : **https://en.wikipedia.org/wiki/Rijndael_MixColumns**


Ensuite, on Xor chaque octet avec l'octet de la clé à son index:

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



### Dechiffrement

Pour le déchiffrement c'est essentiellement les mêmes étapes inversés

Les matrices de sub et de columns ont juste des équivalents inversés



[Vidéo Explicative](https://www.youtube.com/watch?v=gP4PqVGudtg)
 
