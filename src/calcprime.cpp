#include "calcprime.h"

CalcPrime::CalcPrime(QObject *parent)
    : QObject( parent )
    , m_bCalculate( false )
    , m_curValue( 0 )
    , m_timer()
    , oForm()
{
    m_timer.setInterval( 1 );
    m_timer.setSingleShot( true );

    connect( &m_timer, &QTimer::timeout, this, &CalcPrime::slotTimeOut );

    connect( &oForm, &CalcPrimeForm::signalStartButtonClicked, this, &CalcPrime::slotStartCalculation );
    connect( &oForm, &CalcPrimeForm::signalStopButtonClicked, this, &CalcPrime::slotStopCalculation );

    connect( this, &CalcPrime::signalCurrentValue, &oForm, &CalcPrimeForm::slotUpdateCurrentValue );
    connect( this, &CalcPrime::signalPrimeNumberFound, &oForm, &CalcPrimeForm::slotAddNewPrime );

    oForm.show();
}

void CalcPrime::slotStartCalculation()
{
    m_bCalculate = true;
    slotTimeOut();
}

void CalcPrime::slotStopCalculation()
{
    m_bCalculate = false;
}

void CalcPrime::slotTimeOut()
{
    emit signalCurrentValue( m_curValue );
    if( number_is_prime( m_curValue ) )
    {
        emit signalPrimeNumberFound( m_curValue );
    }

    m_curValue++;

    if( m_bCalculate )
    {
        m_timer.start();
    }
}

bool CalcPrime::number_is_prime(uint64_t number)
{
    uint64_t m = number / 2;

    for( uint64_t i = 2; i <= m; i++ )
    {
        if( number % i == 0 )
        {
            return false;
        }
    }

    return true;
}
