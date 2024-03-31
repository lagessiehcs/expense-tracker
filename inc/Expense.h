#ifndef EXPENSE_H
#define EXPENSE_H

#include <vector>

class Expense
{
private:
    unsigned _id;
    unsigned _amount;
    unsigned _payer_id;
    std::vector<unsigned> _payee_ids;

public:
    Expense(unsigned amount = 0, unsigned payer_id = 0, std::vector<unsigned> payee_ids = {});
    unsigned id() const;
    unsigned amount() const;
    unsigned payer_id() const;
    std::vector<unsigned> payee_ids() const;
    void edit(unsigned amount);

    // static class member: shared across all class objects
    // inline: so we can initialize it here.
    static inline unsigned counter{0};
};

#endif
