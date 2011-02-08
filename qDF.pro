######################################################################
# Automatically generated by qmake (2.01a) Tue Apr 21 22:09:14 2009
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

QT += network
CONFIG += warn_off
#CONFIG += debug

qDF.path=$$[QT_INSTALL_BINS]
qDF.files=qDF
INSTALLS += qDF

# Input
HEADERS += CoordSysBuilder.hpp \
           Settings.hpp \
           APRS.hpp \
           getReportDialog.h \
           settingsDialog.h \
           reportToggleDialog.h \
           latLonCoordinatewidget.h \
           MainWindow.h \
           qDFProjReport.hpp \
           qDFProjReportCollection.hpp\
           qDFDisplayInterface.hpp \
           aprsDisplay.hpp \
           rawTextDisplay.hpp \
           kmlDisplay.hpp \
           qDFDisplayManager.hpp
FORMS += getReportDialog.ui MainWindow.ui reportToggleDialog.ui latLonCoordinateWidget.ui  settingsDialog.ui
SOURCES += CoordSysBuilder.cpp \
           Settings.cpp \
           APRS.cpp \
           getReportDialog.cpp \
           latLonCoordinatewidget.cpp \
           reportToggleDialog.cpp \
           settingsDialog.cpp \
           main.cpp \
           MainWindow.cpp \
           qDFProjReport.cpp \
           qDFProjReportCollection.cpp \
           aprsDisplay.cpp \
           rawTextDisplay.cpp \
           kmlDisplay.cpp \
           qDFDisplayManager.cpp

LIBS += -L/users/tvrusso/src/DFLib/build -lDFLib -lproj
INCLUDEPATH += /users/tvrusso/src/DFLib

