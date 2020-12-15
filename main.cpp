#include "mainwindow.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "sculptor.h"
#include "interpretador.h"
#include "figurageometrica.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    Sculptor *s1;

       interpretador parser;

       vector<Figurageometrica*>figs;

       figs = parser.parse("escultura.txt");

       s1 = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());


       for(size_t i=0;i<figs.size();i++){
           cout << "draw" << endl;
           figs[i]->draw(*s1);
       }


       s1->writeOFF((char*) "teste.off");
       for(size_t i=0;i<figs.size();i++){
           delete figs[i];
       }
       delete s1;
       return 0;
}
