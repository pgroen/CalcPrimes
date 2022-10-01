#include <QApplication>

#include "calcprime_form.h"

int main( int argc, char* argv[] )
{
    QApplication oApp( argc, argv );

    CalcPrimeForm oForm;
    oForm.show();

     oApp.exec();
}

