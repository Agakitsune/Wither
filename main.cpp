#include <iostream>
#include <map>
#include <qt6/QtWidgets/QApplication>
#include <qt6/QtWidgets/QPushButton>
#include <qt6/QtWidgets/QWidget>
#include <variant>
#include <vector>

#include "WitherConfig.h"
#include "nbt/Misc.hpp"
#include "nbt/Parser.hpp"
#include "nbt/Tag.hpp"
// #include <QtGui>

struct MyWindow {
    QWidget window;

    MyWindow& resize(int w, int h) {
        window.resize(w, h);
        return *this;
    }

    MyWindow& show() {
        window.show();
        return *this;
    }

    MyWindow& setWindowTitle(const std::string& title) {
        window.setWindowTitle(QString(title.c_str()));
        return *this;
    }

};

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    MyWindow window;
    window.resize(300, 300).show().setWindowTitle("Furr");

    QPushButton button("Bruh", &window.window);
    button.move(100, 100);
    button.show();

    return app.exec();
}
