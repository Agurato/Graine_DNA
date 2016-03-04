QT += widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    dna_strands/EyeStrand.cpp \
    dna_strands/LimbStrand.cpp \
    dna_strands/Strand.cpp \
    utils/utils.cpp \
    mainwindow.cpp \
    dna_strands/EarStrand.cpp \
    dna_strands/MouthStrand.cpp \
    dna_strands/NostrilStrand.cpp \
    parts/Eye.cpp \
    parts/XMLData.cpp \
    simfunctions/functions.cpp \
    Creature.cpp \
    DNA.cpp \
    mainParser.cpp \
    mainStrandTest.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
    dna_strands/EyeStrand.hpp \
    dna_strands/LimbStrand.hpp \
	dna_strands/Strand.hpp \
    utils/utils.hpp \
    mainwindow.h \
    dna_strands/EarStrand.hpp \
    dna_strands/MouthStrand.hpp \
    dna_strands/NostrilStrand.hpp \
    parts/Eye.hpp \
    parts/XMLData.hpp \
    simfunctions/functions.hpp \
    Creature.hpp \
    DNA.hpp

DISTFILES += \
    README.md
