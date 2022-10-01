#include <QApplication>

#include "calcprime.h"

int main( int argc, char* argv[] )
{
    QApplication oApp( argc, argv );

    CalcPrime   ocalcPrime;

     oApp.exec();
}

