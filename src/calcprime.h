#pragma once

#include "calcprime_form.h"
#include <QObject>

class CalcPrime : public QObject
{
    Q_OBJECT

public:
    explicit    CalcPrime(QObject *parent = nullptr);

private:
    bool        m_bCalculate;
    uint64_t    m_curValue;

signals:
    void        signalCurrentValue( uint64_t current_value );
    void        signalPrimeNumberFound( uint64_t prime_number );

private slots:
    void        slotStartCalculation();
    void        slotStopCalculation();
};
