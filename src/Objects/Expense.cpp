#include "../../inc/Objects/Expense.h"

Expense::Expense(unsigned amount, unsigned payer_id, std::vector<unsigned> payee_ids)
    : _id(counter++), _amount(amount), _payer_id(payer_id), _payee_ids(payee_ids){};

unsigned Expense::id() const
{
    return _id;
};

unsigned Expense::amount() const
{
    return _amount;
};

unsigned Expense::payer_id() const
{
    return _payer_id;
}

std::vector<unsigned> Expense::payee_ids() const
{
    return _payee_ids;
}

void Expense::edit(unsigned amount)
{
    _amount = amount;
}