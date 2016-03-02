QT += widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
	fencalc.cpp \
    dna_strands/EyeStrand.cpp \
    dna_strands/LimbStrand.cpp \
    dna_strands/Strand.cpp \
    utils/utils.cpp

FORMS += \
    fencalc.ui

HEADERS += \
    fencalc.h \
    dna_strands/EyeStrand.hpp \
    dna_strands/LimbStrand.hpp \
	dna_strands/Strand.hpp \
    utils/utils.hpp

DISTFILES += \
    README.md
