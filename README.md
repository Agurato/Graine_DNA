# World of Swag - partie ADN
Projet de synthèse (L3) : Evolution de créatures procédurales

Ce projet, réalisé en C++ a pour but est de réaliser l'évolution de créatures générées procéduralement.

### Bibliothèque graphique utilisée : Qt
```
http://www.qt.io/download-open-source/
```

### Bibliothèqe Xerces-C pour parser le XML
```shell
wget http://www.apache.org/dist/xerces/c/3/sources/xerces-c-3.1.3.tar.bz2
tar -xjvf xerces-c-3.1.3.tar.bz2
cd xerces-c-3.1.3
./configure
make
sudo make install
```
Si à l'éxecution du programme, il y a une erreur (à ajouter au ~/.bashrc) :
```shell
export LD_LIBRARY_PATH=/usr/local/lib
```
