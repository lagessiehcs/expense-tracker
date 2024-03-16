#include "../inc/Expense.h"

Expense::Expense(int id, int amount, int payer_id, std::vector<int> payee_ids)
: _id(id), _amount(amount), _payer_id(payer_id), _payee_ids(payee_ids)
{

};

int Expense::id() const{
    return _id;
};

int Expense::amount() const{ 
    return _amount;
};

int Expense::payer_id() const{
    return _payer_id;
}

std::vector<int> Expense::payee_ids() const{
    return _payee_ids;
}

void Expense::edit(int amount){
    _amount = amount;
}