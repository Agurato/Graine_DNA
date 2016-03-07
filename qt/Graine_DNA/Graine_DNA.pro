#-------------------------------------------------
#
# Project created by QtCreator 2016-03-07T16:31:33
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graine_DNA
TEMPLATE = app


SOURCES += main.cpp\
        simwindow.cpp \
    dna_strands/EarStrand.cpp \
    dna_strands/EyeStrand.cpp \
    dna_strands/LimbStrand.cpp \
    dna_strands/MouthStrand.cpp \
    dna_strands/NostrilStrand.cpp \
    dna_strands/SkinStrand.cpp \
    dna_strands/Strand.cpp \
    sim/functions.cpp \
    sim/XMLData.cpp \
    utils/utils.cpp \
    Creature.cpp \
    DNA.cpp

HEADERS  += simwindow.h \
    dna_strands/EarStrand.hpp \
    dna_strands/EyeStrand.hpp \
    dna_strands/LimbStrand.hpp \
    dna_strands/MouthStrand.hpp \
    dna_strands/NostrilStrand.hpp \
    dna_strands/SkinStrand.hpp \
    dna_strands/Strand.hpp \
    sim/functions.hpp \
    sim/XMLData.hpp \
    utils/utils.hpp \
    Creature.hpp \
    DNA.hpp

FORMS    += simwindow.ui

unix:!macx: LIBS += -L$$PWD/../../../../../../../usr/local/lib/ -lxerces-c-3.1

INCLUDEPATH += $$PWD/../../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../../usr/local/include
