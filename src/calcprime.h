#pragma once

#include "calcprime_form.h"

#include <QObject>
#include <QTimer>

class CalcPrime : public QObject
{
    Q_OBJECT

public:
    explicit    CalcPrime(QObject *parent = nullptr);

signals:
    void        signalCurrentValue( uint64_t current_value );
    void        signalPrimeNumberFound( uint64_t prime_number );

private slots:
    void        slotStartCalculation();
    void        slotStopCalculation();
    void        slotTimeOut();

private:
    bool        number_is_prime(uint64_t number);

private:
    bool        m_bCalculate;
    uint64_t    m_curValue;
    QTimer      m_timer;

    CalcPrimeForm   oForm;

};
