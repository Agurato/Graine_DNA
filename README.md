# World of Swag
Projet de synthèse (L3) : Evolution de créatures procédurales

Ce projet, réalisé en C++ a pour but est de réaliser l'évolution de créatures générées procéduralement.

### TODO (08/02/16)

- Chacun des brins sera une classe fille de Strand et sera dans "dna_strands/"
- dossier "parts/" sert à représenter les parties de l'animal

### Récap réunion 04/02/16

###### Définition d'un brin d'ADN

- A part (peut-être fixe) :							=>	35
	- pilosité (rien, fourrure)						->	1
	- couleur de peau (en hexa)						->	24
	- poids											->	10
- œil :												=>	27+2n /
	- nombre :										->	3
		- lieu pour chaque œil						->	2*n
	- couleur (en hexa : 24 bits)					->	24
- oreille :											=>	3+2n
	- nombre :										->	3
		- lieu pour chaque œil						->	2*n
- narine :											=>	3+2n
	- nombre :										->	3
		- lieu pour chaque œil						->	2*n
- bouche :											=>	3n
	- nombre :										->	3
		- taille (petite, grande)					->	n
		- lieu										->	2*n
- membre :											=>	4+14n
	- nombre :										->	4
		- taille									 >	10*n
		- lieu										 >	2*n
		- extrémité (main, pied, sabot, tête + cou)	 >	2*n
