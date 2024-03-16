#ifndef EXPENSE_H
#define EXPENSE_H

#include <vector> 

class Expense {
    private:
        int _id;
        int _amount;
        int _payer_id;
        std::vector<int> _payee_ids;

    public:
        Expense(int id = 0, int amount = 0, int payer_id = 0, std::vector<int> payee_ids = {});
        int id() const;
        int amount() const;
        int payer_id() const;
        std::vector<int> payee_ids() const;
        void edit(int amount);
};

#endif
