QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        Player.cpp \
        Hangman.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
        Player.h \
        Hangman.h

DEFINES += __QT_CREATOR__

# IMPORTANT: when compiling using QT Creator and the ahpset1-hangman.pro project file
# on the UB school computers, the build process may hang half-way through. To fix that,
# simply make a non-affecting edit to the ahpset1-hangman.pro file e.g. remove this comment block
# then building will work. Afterward, remove the edit and the build should succeed.