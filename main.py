#!/usr/bin/python

import sys
from PyQt4 import QtCore,QtGui
from PyQt4.QtGui import *
from edytor import Ui_notepad

class FirstWin(QMainWindow):
    def __init__(self):
        QWidget.__init__(self, parent=None)
        self.ui = Ui_notepad()
        self.ui.setupUi(self)
        QtCore.QObject.connect(self.ui.openfile, QtCore.SIGNAL('clicked()'), self.file_dialog)

    def file_dialog(self):
        self.ui.textEdit.setText('aaaaaaaaa')


if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = FirstWin()
    window.show()
    sys.exit(app.exec_())

