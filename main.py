#!/usr/bin/python3

import sys
from PyQt4 import QtCore, QtGui
from PyQt4.QtGui import *
from PyQt4.QtCore import QFile, QTextStream
from edytor import Ui_notepad


class FirstWin(QMainWindow):
    def __init__(self):
        QWidget.__init__(self, parent=None)
        self.ui = Ui_notepad()
        self.ui.setupUi(self)
        QtCore.QObject.connect(self.ui.openfile, QtCore.SIGNAL('clicked()'), self.file_dialog)
        QtCore.QObject.connect(self.ui.saveButton, QtCore.SIGNAL('clicked()'), self.save_file)
        self.setupMenubar()

    def file_dialog(self):
        fn = QFileDialog.getOpenFileName(self,
                                            "Open File", "/home/", "")
        self.myfile = QFile(fn)
        self.myfile.open(QtCore.QIODevice.ReadOnly)
        mystream = QTextStream(self.myfile)
        mystr = mystream.readAll()
        self.ui.textEdit.setText(mystr)
        self.myfile.close()

    def save_file(self):
        self.myfile.open(QtCore.QIODevice.WriteOnly)
        mystream = QTextStream(self.myfile)
        mystream << self.ui.textEdit.toPlainText()

    def setupMenubar(self): 
        exitAction = QtGui.QAction('&Exit', self) 
        exitAction.setShortcut('Ctrl+Q')
        exitAction.setStatusTip('Exit application')
        exitAction.triggered.connect(QtGui.qApp.quit)
        fileMenu = self.ui.menubar.addMenu('&File')
        fileMenu.addAction(exitAction)
        fileMenu.setGeometry(QtCore.QRect(20, 20, 20, 20))

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = FirstWin()
    window.show()
    sys.exit(app.exec_())
