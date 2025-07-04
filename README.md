# AES128
Petit AES128 pour tester

Pour l'instant ce projet ne contient pas de constante RCON

AES128 fonctionne par bloc, en matrice de 4*4 octets
Il se base essentiellement sur le Xor
Il génère 10 clés de chiffrement chacun dérivé de la précédente

Pour chaque matrice, il va:
    changer la valeur de chaque octet selon un tableau subByte en fonction de leur valeur:
        ex : 0x38 -> subByteTab[3][8]
    Decaler les lignes
    Mixer les colonnes avec la formule de Rijndael
    Et Xor chaque octet avec l'octet de la clé à son index:
        ex:
            [1 2 3 4]   [F E D 0]
            [5 6 7 8]   [C B A 9]
            [9 A B C]   [8 7 6 5]
            [0 D E F]   [4 3 2 1]

            1 sera xor avec F, 2 avec E, 3 avec D etc...
    Ces etapes vont se répéter 9 fois, avec la clé qui change à chaque tour
    Pour la 10ème étape, c'est pareil mais on ne mixe pas les colonnes

    et la le message est chiffré et presque incassable
 
