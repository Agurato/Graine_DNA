QT += widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    dna_strands/EyeStrand.cpp \
    dna_strands/LimbStrand.cpp \
    dna_strands/Strand.cpp \
    utils/utils.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
    dna_strands/EyeStrand.hpp \
    dna_strands/LimbStrand.hpp \
	dna_strands/Strand.hpp \
    utils/utils.hpp \
    mainwindow.h

DISTFILES += \
    README.md
