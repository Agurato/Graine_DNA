QT += widgets

CONFIG += c++11

SOURCES += \
	main.cpp \
	mainwindow.cpp \
    dna_strands/EarStrand.cpp \
    dna_strands/EyeStrand.cpp \
    dna_strands/LimbStrand.cpp \
    dna_strands/MouthStrand.cpp \
    dna_strands/NostrilStrand.cpp \
    dna_strands/SkinStrand.cpp \
    dna_strands/Strand.cpp \
    parts/Eye.cpp \
    parts/XMLData.cpp \
    simfunctions/functions.cpp \
    utils/utils.cpp \
    Creature.cpp \
    DNA.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
	mainwindow.h \
    dna_strands/EarStrand.hpp \
    dna_strands/EyeStrand.hpp \
    dna_strands/LimbStrand.hpp \
    dna_strands/MouthStrand.hpp \
    dna_strands/NostrilStrand.hpp \
    dna_strands/SkinStrand.hpp \
    dna_strands/Strand.hpp \
    parts/Eye.hpp \
    parts/XMLData.hpp \
    simfunctions/functions.hpp \
    utils/utils.hpp \
    Creature.hpp \
    DNA.hpp

DISTFILES += \
    README.md

unix:!macx: LIBS += -L/usr/local/lib/ -lxerces-c

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include
