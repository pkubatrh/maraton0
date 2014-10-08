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

    def file_dialog(self):
        fn = QFileDialog.getOpenFileName(self,
                                            "Open File", "/home/", "")
        myfile = QFile(fn)
        myfile.open(QtCore.QIODevice.ReadWrite)
        mystream = QTextStream(myfile)
        mystr = mystream.readAll()
        self.ui.textEdit.setText(mystr)
if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = FirstWin()
    window.show()
    sys.exit(app.exec_())
