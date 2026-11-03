QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appmodel.cpp \
    databaseapi.cpp \
    databaseconnform.cpp \
    entryform.cpp \
    main.cpp \
    mainwindow.cpp \
    tableform.cpp

HEADERS += \
    appmodel.h \
    databaseapi.h \
    databaseconnform.h \
    entryform.h \
    mainwindow.h \
    structs.h \
    tableform.h

FORMS += \
    databaseconnform.ui \
    entryform.ui \
    mainwindow.ui \
    tableform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/../../../../libs/mysql-connector/lib64/vs14/ -lmysqlcppconnx

INCLUDEPATH += $$PWD/../../../../libs/mysql-connector/include/mysqlx
DEPENDPATH += $$PWD/../../../../libs/mysql-connector/include/mysqlx
