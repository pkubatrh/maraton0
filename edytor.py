# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'editor.ui'
#
# Created: Wed Oct  8 12:12:22 2014
#      by: PyQt4 UI code generator 4.10.2
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_notepad(object):
    def setupUi(self, notepad):
        notepad.setObjectName(_fromUtf8("notepad"))
        notepad.resize(800, 600)
        self.centralwidget = QtGui.QWidget(notepad)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.openfile = QtGui.QPushButton(self.centralwidget)
        self.openfile.setGeometry(QtCore.QRect(0, 20, 85, 27))
        self.openfile.setObjectName(_fromUtf8("openfile"))
        self.saveButton = QtGui.QPushButton(self.centralwidget)
        self.saveButton.setGeometry(QtCore.QRect(110, 20, 85, 27))
        self.saveButton.setObjectName(_fromUtf8("saveButton"))
        self.textEdit = QtGui.QTextEdit(self.centralwidget)
        self.textEdit.setGeometry(QtCore.QRect(3, 74, 791, 491))
        self.textEdit.setObjectName(_fromUtf8("textEdit"))
        notepad.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(notepad)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 20))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        notepad.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(notepad)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        self.statusbar.showMessage('Welcome to this fucking application', 10000)
        notepad.setStatusBar(self.statusbar)

        self.retranslateUi(notepad)
        self.setupMenubar(notepad)
        QtCore.QMetaObject.connectSlotsByName(notepad)

    def retranslateUi(self, notepad):
        notepad.setWindowTitle(_translate("notepad", "MainWindow", None))
        self.openfile.setText(_translate("notepad", "Open File", None))
        self.saveButton.setText(_translate("notepad", "Save your shit", None))

    def setupMenubar(self, notepad): 
        exitAction = QtGui.QAction('&Exit', self) 
        exitAction.setShortcut('Ctrl+Q')
        exitAction.setStatusTip('Exit application')
        exitAction.triggered.connect(QtGui.qApp.quit)
        fileMenu = self.menubar.addMenu('&File')
        fileMenu.addAction(exitAction)
        fileMenu.setGeometry(QtCore.QRect(20, 20, 20, 20))
        

