#include "calcprime_form.h"

#include <string>
#include <QString>

CalcPrimeForm::CalcPrimeForm(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
    connectSignalsAndSlots();
}

void CalcPrimeForm::connectSignalsAndSlots()
{
    connect( this->cmdStartButton, &QPushButton::clicked, this, &CalcPrimeForm::slotStartButtonClicked );
    connect( this->cmdStopButton, &QPushButton::clicked, this, &CalcPrimeForm::slotStopButtonClicked );
}

void CalcPrimeForm::slotUpdateCurrentValue( uint64_t value )
{
    this->currentValue->display( QString( std::to_string( value ).c_str() ) );
}

void CalcPrimeForm::slotAddNewPrime( uint64_t new_prime )
{
    this->listPrimes->addItem(QString( std::to_string( new_prime ).c_str() ));
}

void CalcPrimeForm::slotStartButtonClicked()
{
    this->cmdStartButton->setDisabled(true);
    this->cmdStopButton->setDisabled(false);
    emit signalStartButtonClicked();
}

void CalcPrimeForm::slotStopButtonClicked()
{
    this->cmdStopButton->setDisabled(true);
    this->cmdStartButton->setDisabled(false);
    emit signalStopButtonClicked();
}
