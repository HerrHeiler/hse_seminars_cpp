#include <climits>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>


using UnixTS = unsigned int;

const unsigned short TRANSACTION_COL_N = 6;
const unsigned short ACCOUNT_COL_N = 3;

struct Transaction {
    std::string id;
    UnixTS date;
    std::string type;
    std::string from;
    std::string to;
    double amount;
    bool operator<(const Transaction& other) const;
};

struct Account {
    Account();// default constructor
    Account(const std::string& id, const std::string& name, UnixTS validity_dt = UINT_MAX);
    void addTransaction(const Transaction& transaction);
    double getBalance(UnixTS = UINT_MAX) const;
    void printInfo() const;
    size_t getTransactionsCount() const;

    std::string id;
    std::string name;
    std::set<Transaction> transactions;
    UnixTS validity_dt;
};

void Account::printInfo() const
{
    std::cout << "--------------------------------\n"
              << "id: " << id << '\n'
              << "name: " << name << '\n'
              << "validity datetime: " << validity_dt << '\n'
              << "--------------------------------\n";
}

size_t Account::getTransactionsCount() const
{
    return transactions.size();
}

Account::Account()
{
    id = "00000000-0000-0000-0000-000000000000";
    name = "Noname";
    validity_dt = 0;
}
// Task 1 (5 points)
// Implement Account constructor with arguments
Account::Account(const std::string& id,
                 const std::string& name,
                 UnixTS validity_dt) : id(id), name(name), validity_dt(validity_dt)
{
    // put your code here;
}

// Task 2 (10 points)
// Implement operator< overloading for Transaction
bool Transaction::operator<(const Transaction& other) const
{
    if (date < other.date) return true;
    else if (date > other.date) return false;
    else if ((type == "deposit" && other.type != "deposit") || (other.type == "transfer" && type != "transfer")) return true; 
    return false;
}

// Task 3 (15 points)
// Implement adding transaction to Account
void Account::addTransaction(const Transaction& transaction)
{
    transactions.insert(transaction);
}

// Task 4 (10 points)
// Implement get balance to date method (default max value)
double Account::getBalance(UnixTS timestamp) const
{
    double balance = 0;
    for (const auto& tr : transactions) {
        if (tr.date <= timestamp) {
            if (tr.type == "deposit") balance += tr.amount;
            else if (tr.type == "withdraw") balance -= tr.amount;
            else {
                if (tr.from == id) balance -= tr.amount;
                if (tr.to == id) balance += tr.amount;
            }
        }
    }
    return balance;
}


// Task 5 (20 points)
// Implement transaction and account reading from csv and fill accounts by transactions
using AccountContainer = std::unordered_map<std::string, Account>;
using TransactionContainer = std::set<Transaction>;

TransactionContainer readTransactions(std::ifstream& fileStream)
{
    TransactionContainer transactions;

    std::string line;
    std::getline(fileStream, line);
    size_t transactionsCount = std::stoul(line);
    std::getline(fileStream, line);

    for (size_t i = 0; i < transactionsCount; ++i)
    {
        std::getline(fileStream, line);
        std::stringstream ss(line);
        std::string field;
        Transaction transaction;
        for (unsigned short j = 0; j < TRANSACTION_COL_N; j++)
        {
            //id;timestamp;type;from;to;amount
            std::getline(ss, field, ';');
            switch (j) {
            case 0 : transaction.id = field; break;
            case 1 : transaction.date = std::stoul(field); break;
            case 2 : transaction.type = field; break;
            case 3 : transaction.from = field; break;
            case 4 : transaction.to = field; break;
            case 5 : transaction.amount = std::stod(field); break;
            }
        }
        transactions.insert(transaction);
    }
    return transactions;
}

AccountContainer readAccounts(std::ifstream& fileStream)
{
    AccountContainer accounts;

    std::string line;
    std::getline(fileStream, line);
    size_t num = std::stol(line);
    std::getline(fileStream, line);
    for (int i = 0; i < num; ++i) {
        std::getline(fileStream, line);
        std::stringstream ss(line);
        std::string field;
        Account account;
        for (int j = 0; j < ACCOUNT_COL_N; ++j) {
            std::getline(ss, field, ';');
            switch (j) {
                //id;name;validity_timestamp
                case 0 : account.id = field; break;
                case 1 : account.name = field; break;
                case 2 : account.validity_dt = std::stol(field); break;
            }
        }
        accounts[account.id] = account;
    }

    return accounts;
}

void fillAccounts(AccountContainer& accounts, const TransactionContainer& transactions)
{
    for (const auto& tr : transactions) {
        if (accounts.find(tr.from) != accounts.end()) accounts[tr.from].addTransaction(tr);
        if (accounts.find(tr.to) != accounts.end()) accounts[tr.to].addTransaction(tr);
    }
}
