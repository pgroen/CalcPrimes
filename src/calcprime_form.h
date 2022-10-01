
#pragma once

#include "ui_calcprime_form.h"

class CalcPrimeForm : public QWidget, private Ui::wdgPrimeGui
{
    Q_OBJECT

public:
    explicit CalcPrimeForm(QWidget *parent = nullptr);

private:
    void    connectSignalsAndSlots();

signals:
    void    signalStartButtonClicked();
    void    signalStopButtonClicked();

public slots:
    void    slotUpdateCurrentValue( uint64_t value );
    void    slotAddNewPrime( uint64_t new_prime );

private slots:
    void    slotStartButtonClicked();
    void    slotStopButtonClicked();
};
